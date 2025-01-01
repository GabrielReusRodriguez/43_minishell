/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_pipeline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:15:38 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 21:16:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "pipe.h"
#include "fd.h"
#include "builtins.h"
#include "executor.h"

static bool	prepare_pipes(t_pipe *cmd_pipe)
{
	*cmd_pipe = pipe_new();
	if(!pipe_open(cmd_pipe))
		return (false);
	return(true);
}

static	bool execute_child(t_cmd *cmd, t_pipe cmd_pipe, t_minishell *shell)
{
	if (cmd->fd_out == FD_NONE)
		cmd->fd_out = cmd_pipe.write;
	if (cmd->fd_in != FD_NONE)
		if (!fd_replace(cmd->fd_in, STDIN_FILENO))
			exit(EXIT_FAILURE);
	if (cmd->type == CMD_TYPE_PIPE)
	{
		if (!fd_replace(cmd->fd_out, STDOUT_FILENO) || \
			!fd_close(cmd_pipe.read))
			exit (EXIT_FAILURE);
	}
	else
	{
		if (!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
			exit (EXIT_FAILURE);
	}
	if (is_builtin(cmd))
			execute_builtin(cmd, shell, true);
	else
	{
		cmd->return_value = EXIT_SUCCESS;
		if (!executor_execve(shell, cmd))
				cmd->return_value = EXIT_FAILURE;
	}
//	if (cmd->type == CMD_TYPE_PIPE)
//	{
		//fd_close(cmd_pipe.write);
	fd_close(cmd->fd_out);
//	}
	exit(cmd->return_value);
}

static bool	execute_parent(t_cmd *cmd, t_pipe *cmd_pipe, t_minishell *shell)
{
	if (cmd->type == CMD_TYPE_PIPE)
	{
		//Si  es una pipe y NO hay redireccion de salida,  hacemos el piping normal. SI no, cerramos pipes
		if (cmd->fd_out == FD_NONE)
		{
			if (!fd_replace(cmd_pipe->read, STDIN_FILENO))
			{
				pipe_close(cmd_pipe);
				return (false);
			}
		}
		return (pipe_close(cmd_pipe));
	}
	else
	{
		//No hay pipe abierta...
		if (!fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO) || \
			!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
			return (false);
	}
	return (true);
}

bool	execute_cmd_pipeline(t_minishell *shell, t_cmd *cmd)
{
	t_pipe	cmd_pipe;
	t_pipe	*pipe;

	pipe = NULL;
	//Creo la pipe SOLO si tengo otro cmd pipe detras.
	if (cmd->type == CMD_TYPE_PIPE)
	{
		if (!prepare_pipes(&cmd_pipe))
			return (false);
		pipe = &cmd_pipe;
	}
	if (!cmd_prepare_redirs(cmd, pipe, shell))
		return (false);
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
			execute_child(cmd, cmd_pipe, shell);
		//En caso del padre...
		else
			return (execute_parent(cmd, &cmd_pipe, shell));
	}
	return (true);
}

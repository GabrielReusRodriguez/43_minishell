/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_pipeline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:15:38 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 19:41:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "pipe.h"
#include "fd.h"
#include "builtins.h"
#include "executor.h"

static bool	execute_prepare_pipes(t_pipe *cmd_pipe)
{
	*cmd_pipe = pipe_new();
	if(!pipe_open(cmd_pipe))
		return (false);
	return(true);
}

bool	execute_cmd_pipeline(t_minishell *shell, t_cmd *cmd)
{
	t_pipe cmd_pipe;

	//Creo la pipe SOLO si tengo otro cmd pipe detras.
	if (cmd->type == CMD_TYPE_PIPE && cmd->output_redirections == FD_NONE)
	{
		if (!execute_prepare_pipes(&cmd_pipe))
			return (false);
		cmd->output_redirections = cmd_pipe.write;
	}
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
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
			if (cmd->type == CMD_TYPE_PIPE)
			{
				//fd_close(cmd_pipe.write);
				fd_close(cmd->fd_out);
			}
			exit(cmd->return_value);
		}
		//En caso del padre...
		else
		{	if (cmd->type == CMD_TYPE_PIPE)
			{
				if (!fd_replace(cmd_pipe.read, STDIN_FILENO) || \
					!fd_close(cmd_pipe.write) || !fd_close(cmd_pipe.read))
				{
					fd_close(cmd_pipe.read);
					return (false);
				}
			}
			else
			{
				if (!fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO) || !fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
					return (false);
			}
		}
	}
	return (true);
}

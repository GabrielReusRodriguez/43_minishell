/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/22 19:44:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"
#include "builtins.h"
#include "executor.h"
#include "pipe.h"
#include "fd.h"

#include <stdio.h>

static bool	execute_non_pipeline_cmd(t_minishell *shell, t_cmd *cmd)
{
	bool	cmd_builtin;

	//Volvemos los fds a lo normal de stdout.
	if (!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
	{
		cmd->return_value = EXIT_FAILURE;
		return (false);
	}
	cmd_builtin = is_builtin(cmd); 
	if (cmd_builtin)
	{
		if (!execute_builtin(cmd, shell))
			return (false);
	}
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
//		printf("cmd->pid: %d\n", cmd->pid);
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
			if (cmd_builtin)
				exit(cmd->return_value);
			else
			{
//				printf("PRE-execve\n");
				if (!executor_execve(shell, cmd))
					exit(EXIT_FAILURE);
				
			}
		}
		else
		{
			//Como padre volvemos los fds a lo normal de stdin.
			if (!fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO))
			{
				cmd->return_value = EXIT_FAILURE;
				return (false);
			}
		}
	}
	return (true);
}

static bool	execute_prepare_pipes(t_pipe *cmd_pipe)
{
	*cmd_pipe = pipe_new();
	if(!pipe_open(cmd_pipe))
		return (false);
	return(true);
}

static bool	execute_pipeline_cmd(t_minishell *shell, t_cmd *cmd)
{
	t_pipe cmd_pipe;

	if (!execute_prepare_pipes(&cmd_pipe))
		return (false);	
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
			if (!fd_replace(cmd_pipe.write, STDOUT_FILENO) || \
					!fd_close(cmd_pipe.read))
				exit (EXIT_FAILURE);
			if (!executor_execute_logic(shell, cmd))
			{
				fd_close(cmd_pipe.write);
				exit(EXIT_FAILURE);
			}
			fd_close(cmd_pipe.write);
			exit(cmd->return_value);
		}
		//En caso del padre...
		else
		{
			if (!fd_replace(cmd_pipe.read, STDIN_FILENO) || \
					!fd_close(cmd_pipe.write) || !fd_close(cmd_pipe.read))
			{
				fd_close(cmd_pipe.read);
				return (false);
			}
		}		
	}
	return (true);
}

bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	if (is_pipeline)
	{
//		printf("\tEntra en pipeline cmd...\n");
		return (execute_pipeline_cmd(shell, cmd));
	}
	else
	{
//		printf("\tEntra en NON pipeline cmd...\n");
		return (execute_non_pipeline_cmd(shell, cmd));
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_non_pipeline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:15:36 by gabriel           #+#    #+#             */
/*   Updated: 2025/01/01 20:34:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "cmd.h"
#include "fd.h"
#include "builtins.h"
#include "executor.h"

static bool	execute_builtin_non_pipe(t_minishell *shell, t_cmd *cmd)
{
	bool	result;

	result = execute_builtin(cmd, shell, false);
	if (cmd->fd_out != FD_NONE)
		if (!fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
			return (false);
	return (result);
}

bool	execute_cmd_non_pipeline(t_minishell *shell, t_cmd *cmd)
{
	cmd->pid = CMD_NO_PID;
	if (!cmd_prepare_redirs(cmd))
		return (false);
	if (is_builtin(cmd))
		return (execute_builtin_non_pipe(shell, cmd));
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
			if (!executor_execve(shell, cmd))
				exit(EXIT_FAILURE);
		}
		else
		{
			//Padre...
			if (cmd->fd_out != FD_NONE && !fd_replace(shell->config.fd_copy_stdout, STDOUT_FILENO))
				return (false);
			if (cmd->fd_in != FD_NONE && !fd_replace(shell->config.fd_copy_stdin, STDIN_FILENO))
				return (false);
		}
	}
	return (true);
}

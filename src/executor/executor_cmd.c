/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/17 21:19:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"
#include "builtins.h"
#include "executor.h"

#include <stdio.h>

/*
static	bool	execute_execve(t_minishell *shell, t_cmd *cmd)
{
	(void)shell;
	(void)cmd;
	return (true);
}
*/

static bool	execute_non_pipeline_cmd(t_minishell *shell, t_cmd *cmd)
{
	bool	cmd_builtin;

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
		//En caso del hijo....
		if (cmd->pid  == 0)
		{
			if (cmd_builtin)
				exit(cmd->return_value);
			else
			{
				if (!executor_execve(shell, cmd))
					return (false);
			}
		}
	}
	return (true);
}

static bool	execute_pipeline_cmd(t_minishell *shell, t_cmd *cmd)
{
		cmd->pid = fork();
		if (cmd->pid < 0)
			return (ft_err_errno(NULL),false);
		else
		{
			//En caso del hijo....
			if (cmd->pid  == 0)
			{
				if (!executor_execute_logic(shell, cmd))
					exit(EXIT_FAILURE);
				exit(cmd->return_value);
			}
			//En caso del padre...
			else
			{
			
			}		
		}
		return (true);
}

bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, bool is_pipeline)
{
	if (is_pipeline)
	{
		return (execute_pipeline_cmd(shell, cmd));
	}
	else
	{
		return (execute_non_pipeline_cmd(shell, cmd));
	}
	return (true);
}
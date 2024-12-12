/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/12 20:57:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"
#include "builtins.h"
#include "executor.h"

#include <stdio.h>


static bool	execute_non_pipeline_cmd(t_minishell *shell, t_cmd *cmd)
{
	if (!executor_execute_logic(shell, cmd))
		return (false);
	cmd->pid = fork();
	if (cmd->pid < 0)
		return (ft_err_errno(NULL),false);
	else
	{
		//En caso del hijo....
		if (cmd->pid  == 0)
			exit(cmd->return_value);
		//En caso del padre...
		else
		{
		
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
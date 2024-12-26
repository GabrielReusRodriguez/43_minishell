/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd_non_pipeline.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:15:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/26 22:14:13 by gabriel          ###   ########.fr       */
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

bool	execute_cmd_non_pipeline(t_minishell *shell, t_cmd *cmd)
{
	cmd->pid = CMD_NO_PID;
	if (is_builtin(cmd))
		return (execute_builtin(cmd, shell, false));
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
		}
	}
	return (true);
}

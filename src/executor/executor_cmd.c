/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 21:20:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"
#include "builtins.h"

#include <stdio.h>

bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, \
			bool is_pipeline, bool unique_cmd)
{
	if (unique_cmd && is_builtin(cmd))
	{
		shell->last_status = execute_builtin(cmd, shell);
		return (true);
	}
	(void)is_pipeline;
	return (true);
}
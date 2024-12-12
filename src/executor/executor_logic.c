/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:29:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/12 20:11:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cmd.h"
#include "builtins.h"

bool	executor_execute_logic(t_minishell *shell, t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (execute_builtin(cmd, shell));
	else
	{
		cmd->return_value = EXIT_SUCCESS;
	}
	return (true);
}
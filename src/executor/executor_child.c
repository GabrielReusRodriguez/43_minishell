/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:29:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/11 21:35:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cmd.h"
#include "builtins.h"

bool	executor_execute_child(t_minishell *shell, t_cmd *cmd)
{
	if (is_builtin(cmd))
	{
		execute_builtin(cmd, shell);
		exit (cmd->return_value);

	}
	else
	{
		exit (EXIT_SUCCESS);
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:37:43 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 20:12:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "cmd.h"
#include "minishell.h"

bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, \
			bool is_pipeline, bool unique_cmd)
{
	if (!unique_cmd)
	{
		if (is_builtin(shell->cmd))
			execute_builtin(shell->cmd, shell);
	}
	(void)cmd;
	(void)unique_cmd;
	return (true);
}
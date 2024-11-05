/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:48:29 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/05 22:49:24 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

bool	minishell_init(t_minishell *shell)
{
	shell->run = true;
	shell->last_status = EXIT_SUCCESS;
	shell->cmd = NULL;
	shell->mode = INTERACTIVE;
	shell->last_status = EXIT_SUCCESS;
	return (true);
}

bool	minishell_destroy(t_minishell *shell)
{
	if (shell->cmd != NULL)
	{
		free(shell->cmd);
		shell->cmd = NULL;
	}
	return (true);
}

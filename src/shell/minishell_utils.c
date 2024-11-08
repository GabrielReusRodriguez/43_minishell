/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:48:29 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 13:25:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "minishell.h"
#include "fd.h"
#include "env/environment.h"

bool	minishell_init(t_minishell *shell, const char **env)
{
	shell->run = true;
	shell->last_status = EXIT_SUCCESS;
	shell->cmd = NULL;
	shell->mode = INTERACTIVE;
	shell->last_status = EXIT_SUCCESS;
	(void)env;
	//env_load(shell->)
	if (!fd_copy(STDIN_FILENO, &shell->config.fd_copy_stdin))
		return (false);
	if (!fd_copy(STDOUT_FILENO, &shell->config.fd_copy_stdout))
		return (false);
	return (true);
}

bool	minishell_destroy(t_minishell *shell)
{
	if (shell->cmd != NULL)
	{
		free(shell->cmd);
		shell->cmd = NULL;
	}
	if (!fd_close(shell->config.fd_copy_stdin) || \
			!fd_close(shell->config.fd_copy_stdout))
		return (false);
	return (true);
}

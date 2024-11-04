/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:36:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 21:59:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include "libft.h"
#include "config.h"

#include "builtins.h"
#include <unistd.h>

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

bool	minishell_loop(t_minishell *shell)
{
	if (shell->mode == STANDALONE)
		shell->run = false;
	else
	{
		shell->cmd = readline(SHELL_DEFAULT_PROMPT);
		if (ft_strlen(shell->cmd) != 0)
		{
			add_history(shell->cmd);
			if (ft_strcmp("exit", shell->cmd) == 0)
				builtin_exit(NULL, shell);
		}
	}
	free (shell->cmd);
	shell->cmd = NULL;
	return (true);
}
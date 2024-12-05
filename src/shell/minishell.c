/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:36:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/05 20:42:09 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"
#include "libft.h"
#include "config.h"
#include "tokenizer/tokenizer.h"
#include "expansor.h"
#include "builtins.h"
#include "job.h"

bool	minishell_loop(t_minishell *shell)
{
	t_list *tokens_list;
	t_job	job;

	job_init(&job);
	tokens_list = NULL;
	if (shell->mode == STANDALONE)
		shell->run = false;
	else
	{
		shell->cmd = readline(SHELL_DEFAULT_PROMPT);
		if (ft_strlen(shell->cmd) != 0)
			add_history(shell->cmd);
	}
	tokenizer_get_tokens(shell->cmd, &tokens_list);
	expansor_expand(&tokens_list, shell->env);
	job_parse_tokens(&tokens_list, &job);
	if (is_builtin(shell->cmd))
		execute_builtin(shell->cmd, shell);
//	else
//		execute_cmd(shell->cmd, shell);
	job_destroy(&job);
	ft_lstclear(&tokens_list, tokenizer_clear_list_node);
	free (shell->cmd);
	shell->cmd = NULL;
	return (true);
}
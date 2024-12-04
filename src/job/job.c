/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:55:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/04 22:06:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "job.h"
#include "libft.h"
#include "tokenizer/token.h"
#include "cmd.h"

bool	job_add_cmd(t_list *init, t_list *final, t_job *job)
{
	t_cmd	*cmd;
	t_list	*node;

	if (!cmd_parse_tokens(init, final, &cmd))
		return(false);
	node = ft_lstnew(cmd);
	if (node == NULL)
	{
		ft_err_errno(NULL);
		cmd_destroy(cmd);
		return(free (cmd), false);
	}
	ft_lstadd_back(&job->cmds, node);
	return (true);
}


bool	job_parse_tokens(t_list **tokens, t_job *job)
{
	t_list	*node;
	t_list	*init_cmd;
	t_token	*token;
	
	node = *tokens;
	init_cmd = node;
	while (node!= NULL)
	{
		token = (t_token *)node;
		if (token->type == TOKEN_TYPE_PIPE || token->type == TOKEN_TYPE_SEMICOLON)
		{
			job_add_cmd(init_cmd, node, job);
			init_cmd = node->next;
		}
		node = node->next;
	}
	return (true);
}
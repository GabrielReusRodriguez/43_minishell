/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:55:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/01 22:21:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "libft.h"
#include "tokenizer/token.h"
#include "cmd.h"

bool	job_add_cmd(t_list *init, t_list *final, t_job *job)
{
	t_cmd	*cmd;
	t_token	*token;
	t_list	*node;

	cmd_parse_tokens(init, final, &cmd);


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
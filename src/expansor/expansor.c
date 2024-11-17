/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:33:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 20:45:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "expansor.h"
#include "env/environment.h"
#include "utils/string.h"

#include <stdio.h>
#include <stdlib.h>


//bool	tokenizer_get_tokens(const char *cmd, t_list **token_list)


static void	expansor_update_token_list(t_list *prev_node, t_list *node, \
				t_list *new_tokens)
{
	t_list	*iter;

	iter = new_tokens;
	if (iter == NULL)
		return;
	while(iter->next != NULL)
		iter = iter->next;
	prev_node->next = new_tokens;
	iter->next = node->next;
	ft_lstdelone(node, tokenizer_clear_list_node);
}

static bool	expansor_expand_node(t_list *node, t_list *last_node, \
				t_environment env)
{
	t_list	*new_token_list;
	t_token	*token;
	char	*new_cmd;

	new_token_list = NULL;
	token = (t_token *)node;
	if (!expansor_expand_string(token->text,env, &new_cmd))
		return (false);
	if (!tokenizer_get_tokens(new_cmd, &new_token_list))
		return (false);
	expansor_update_token_list(last_node, node, new_token_list);
	return (true);
}


bool	expansor_expand(t_list **token_list, t_environment env)
{
	t_list	*node;
	t_list	*last_node;
	
	node = *token_list;
	last_node = NULL;
	while (node != NULL)
	{
		if (!expansor_expand_node(node, last_node, env))
			return (false);
		last_node = node;
		node = node->next;
	}
	return (true);
}


/*
bool	expansor_expand(t_list **token_list, t_environment env)
{
	t_list	*node;
	t_list	*list;
	t_token *token;
	char	*new_cmd;
	
	new_cmd = NULL;
	node = *token_list;
	while (node != NULL)
	{
		token = (t_token *)node->content;
		if (!expansor_expand_string(token->text,env, &new_cmd))
			return (false);
		if (!tokenizer_get_tokens(new_cmd, &list))
			return (false);
		node = node->next;
	}
	return (true);
}
*/
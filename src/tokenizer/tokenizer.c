/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:05:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 00:18:50 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "libft.h"


#include <stdio.h>


static	bool	tokenizer_extract_token(const char *cmd, size_t init, \
					size_t final, t_token **token)
{
	char			*text;
	t_token_type	type;

	text = ft_substr(cmd, init, final - init);
	if (text == NULL)
		return(ft_err_errno(NULL), false);
	type = tokenizer_get_token_type(text);
	if(!token_new(token, text, type))
		return(ft_err_errno(NULL), false);
	printf("token text : _%s_,\n",text);
	return (true);
}

static	bool	tokenizer_get_next_token(const char *cmd, size_t init, \
					size_t *final, t_token **token)
{
	char	init_char;

	init_char= cmd[init];
	if (ft_strchr(TOKENIZER_COMMAND_SEPARATOR, cmd[*final]) != NULL)
			return ((*final)++, tokenizer_extract_token(cmd, init, *final, token));
	while (cmd[*final] != '\0')
	{
		if (init_char == '\"' || init_char == '\'') 
		{
			if (init_char == cmd[*final])
			{
				(*final)++;
				return (tokenizer_extract_token(cmd, init, *final, token));
			}
		}
		else
		{
			if (cmd[*final] == ' ' || \
					ft_strchr(TOKENIZER_COMMAND_SEPARATOR, cmd[*final]) != NULL)
				return (tokenizer_extract_token(cmd, init, *final, token));
		}
		(*final)++;
	}
	if (init != *final)
		return (tokenizer_extract_token(cmd, init, *final, token));
	return (true);
}

static void debug_tokens(t_list *list)
{
	t_list *node;
	t_token *token;

	node = list;
	while(node != NULL)
	{
		token = (t_token *)node->content;
		printf("TOKEN******************\n");
		printf("\ttext: _%s_\n",token->text);
		printf("\ttype: _%d_\n", token->type);
		printf("END TOKEN**************\n");

		node = node->next;
	}
}

static bool	new_node_token_list(t_list **node, t_token *token)
{
	*node = ft_lstnew(token);
	if (*node == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}

bool	tokenizer_get_tokens(const char *cmd, t_list **token_list)
{
	size_t	i;
	size_t	last_read_char;
	t_token	*token;
	t_list	*node;

	i = 0;
	last_read_char = 0;
	while (cmd[i] != '\0')
	{
		while(cmd[i] == ' ' && cmd[i] != '\0')
			i++;
//		last_read_char = i + 1;
		last_read_char = i;
		if (!tokenizer_get_next_token(cmd, i, &last_read_char, &token))
			return (ft_lstclear(token_list, free), false);
		if (!new_node_token_list(&node, token))
		{	
			token_destroy(token);
			free (token);
			ft_lstclear(token_list, free);
			return (false);
		}
		ft_lstadd_back(token_list, node);
		i = last_read_char;
	}
	debug_tokens(*token_list);
	return (true);
}

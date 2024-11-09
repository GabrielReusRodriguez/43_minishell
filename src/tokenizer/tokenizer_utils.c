/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:45:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 22:29:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "tokenizer/token.h"

void	tokenizer_clear_list_node(void *node)
{
	t_token *token;

	token = (t_token *)node;
	token_destroy(token);
	free(token);
}

t_token_type	tokenizer_get_token_type(const char *text)
{	
	if (text != NULL)
	{
		if (*text == '\"')
			return (TOKEN_TYPE_DQUOTE);
		if (*text == '\'')
			return (TOKEN_TYPE_SQUOTE);
		if (*text == '|')
			return (TOKEN_TYPE_PIPE);
		if (*text == ';')
			return (TOKEN_TYPE_SEMICOLON);
		if (*text == '>' || *text == '<')
			return (TOKEN_TYPE_REDIR);
		return (TOKEN_TYPE_WORD);
	}
	return (TOKEN_TYPE_NONE);
}

bool	tokenizer_extract_token(const char *cmd, size_t init, \
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
	return (true);
}

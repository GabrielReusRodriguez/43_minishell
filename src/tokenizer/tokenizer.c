/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:05:21 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 23:17:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "libft.h"

static	bool	tokenizer_extract_token(const char *cmd, size_t init, \
					size_t final, t_token **token)
{
	char	*text;
	
	text = ft_substr(cmd, init, final - init);
	if (text == NULL)
		return(ft_err_errno(NULL), false);
	if(!token_new(token, text, WORD))
		return(ft_err_errno(NULL), false);
	return (true);
}

static	bool	tokenizer_get_next_token(const char *cmd, size_t init, \
					size_t *final, t_token **token)
{
	char	init_char;

	init_char= cmd[init];
	while (cmd[*final] != '\0')
	{
		if (init_char == '\"' || init_char == '\'') 
		{
			if (init_char == cmd[*final])
				return (tokenizer_extract_token(cmd, init, *final, token));
		}
		else
		{
			if (cmd[*final] == ' ')
				return (tokenizer_extract_token(cmd, init, *final, token));
		}
		(*final)++;
	}
	return (true);
}


bool	tokenizer_get_tokens(const char *cmd, t_list **token_list)
{
	size_t	i;
	size_t	last_read_char;
	t_token	*token;

	(void)token_list;
	i = 0;
	last_read_char = 0;
	while (cmd[i] != '\0')
	{
		if (!tokenizer_get_next_token(cmd, i, &last_read_char, &token))
		{
			return (false);
		}
		i = last_read_char;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:56:23 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 23:15:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "tokenizer/token.h"
#include "libft.h"

void	token_init(t_token *token, char *_text, t_token_type _type)
{
	token->text = _text;
	token->type = _type;
}

bool	token_new(t_token **token, char *_text, t_token_type _type)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (*token == NULL)
		return (ft_err_errno(NULL), false);
	token_init(*token, _text, _type);
	return (true);
}

void	token_destroy(t_token *token)
{
	if (token->text != NULL)
	{
		free (token->text);
		token->text = NULL;
	}
}
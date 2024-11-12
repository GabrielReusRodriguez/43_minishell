/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:47:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/12 22:40:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "tokenizer/token.h"


static void	expansor_find_end_var(const char *text, int init, int *final)
{
	int	i;

	i = init;
	while (text[i] != '\0' && text[i] != ' ' && text[i] != '$' && \
				text[i] != '\'' && text[i] != '\"')
		i++;
	*final = i;
}

void		expansor_find_var(t_token *token, int *init, int *final)
{
	int		i;

	i = *init;
	*init 	= -1;
	*final	= -1;
	while (token->text[i] != '\0')
	{
		if (token->text[i] == '\\')
		{
			i+=2;
			continue;
		}
		if (token->text[i] == '\'')
		{
			i++;
			while (token->text[i] != '\'' && token->text[i] != '\0')
				i++;
			continue;
		}
		if (token->text[i] == '$')
		{
			*init = i;
			expansor_find_end_var(token->text, i + 1, final);
			return ;
		}
		i++;
	}
}

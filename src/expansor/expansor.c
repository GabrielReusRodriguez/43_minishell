/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:33:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/12 21:23:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer/token.h"
#include "expansor.h"

#include <stdio.h>
#include <stdlib.h>

static bool	expansor_expand_token(t_list **token_list, t_token *token)
{
	int		init;
	int		final;
	char	*txt;
	
	(void)token_list;
	init = 0;
	final = 0;
	while (init != -1)
	{
		expansor_find_var(token, &init, &final);
		if (init != -1 && final & -1)
		{
			txt = ft_substr(token->text, init, final - init);
			if (txt == NULL)
				return (false);
			printf("\tValor de variable : _%s_\n",txt);
			free (txt);

			init = final;
			final = -1;
		}
	}
	return (true);
}

bool	expansor_expand(t_list **token_list)
{
	t_list	*node;
	t_list	*list;
	
	node = *token_list;
	while (node != NULL)
	{
		if (!expansor_expand_token(&list, (t_token *)node->content))
			return (false);		
		node = node->next;
	}
	return (true);
}
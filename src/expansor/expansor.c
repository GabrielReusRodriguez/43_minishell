/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:33:46 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/17 13:01:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenizer/token.h"
#include "expansor.h"
#include "env/environment.h"

#include <stdio.h>
#include <stdlib.h>

static bool	expansor_expand_token(t_list **token_list, t_token *token, \
				t_environment env)
{
	int		init;
	int		final;
	char	*key;
	char	*value;
	
	(void)env;
	(void)token_list;
	init = 0;
	final = 0;
	while (init != -1)
	{
		expansor_find_var(token, &init, &final);
		if (init != -1 && final & -1)
		{
			key = ft_substr(token->text, init, final - init);
			if (key == NULL)
				return (false);
			//bool	env_get(t_environment env, const char *key, char **value);
			if(!env_get(env, key, &value))
				return (free (key), false);
			printf("\tVariable key : _%s_ value : _%s_ \n",key, value);
			free (key);
			free (value);
			init = final;
			final = -1;
		}
	}
	return (true);
}

bool	expansor_expand(t_list **token_list, t_environment env)
{
	t_list	*node;
	t_list	*list;
	
	(void)env;
	node = *token_list;
	while (node != NULL)
	{
		if (!expansor_expand_token(&list, (t_token *)node->content, env))
			return (false);		
		node = node->next;
	}
	return (true);
}
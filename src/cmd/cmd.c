/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:51:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/01 22:37:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"
#include "libft.h"

bool	cmd_parse_tokens(t_list *init, t_list *final, t_cmd **cmd)
{
	t_token	*token;
	
	*cmd = (t_cmd*)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (ft_err_errno(NULL), false);
	while (init != final)
	{
		token = (t_token *)init;
		if (token->type == TOKEN_TYPE_REDIR)
		{
			continue;
		}
		if (token->type == TOKEN_TYPE_WORD)
		{
			continue;
		}
		if (token->type == TOKEN_TYPE_PIPE || token->type == TOKEN_TYPE_SEMICOLON)
		{
			
		}
		init = init->next;
	}
	return (true);
}
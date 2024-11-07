/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:58:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 00:36:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include "token.h"

# define TOKENIZER_TOKEN_SEPARATOR " \0\t\"\'"
# define TOKENIZER_COMMAND_SEPARATOR "|;"

bool	tokenizer_get_tokens(const char *cmd, t_list **token_list);


//tokenizer_utils.c
void			tokenizer_clear_list_node(void *);
t_token_type	tokenizer_get_token_type(const char * text);
bool			tokenizer_extract_token(const char *cmd, size_t init, \
					size_t final, t_token **token);

#endif
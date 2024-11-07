/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:49:29 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/07 23:35:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

typedef enum e_token_type
{
	NONE,
	WORD,
	DQUOTE,
	SQUOTE,
	PIPE,
	SEMICOLON

}	t_token_type;

typedef struct s_token
{
	char			*text;
	t_token_type	type;
} t_token;

void	token_init(t_token *token, char *_text, t_token_type _type);
bool	token_new(t_token **token, char *_text, t_token_type _type);
void	token_destroy(t_token *token);

#endif
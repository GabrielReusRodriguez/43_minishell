/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:58:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 22:36:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

#define TOKENIZER_TOKEN_SEPARATOR " \0\t\"\'"

bool	tokenizer_get_tokens(const char *cmd, t_list **token_list);

#endif
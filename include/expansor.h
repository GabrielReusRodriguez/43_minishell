/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:47:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/12 20:54:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSOR_H
# define EXPANSOR_H

# include "libft.h"
# include "tokenizer/token.h"

bool	expansor_expand(t_list **token_list);
//t_list	*expansor_expand_token(t_token *token);
void	expansor_find_var(t_token *token, int *init, int *final);


#endif
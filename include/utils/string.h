/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:27:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/11/17 20:52:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H


# include <stdbool.h>

typedef struct s_str_fragment
{
	int begin;
	int end;
} t_str_fragment;

bool			utils_string_unquote(const char *original, char **unquoted);
bool			utils_str_join_compontents(const char *hdr, const char *body, \
					const char *tail, char **final);
t_str_fragment	utils_new_str_fragment(void);


#endif
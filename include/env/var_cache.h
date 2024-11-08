/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cache.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:05:30 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 12:16:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_CACHE_H
# define VAR_CACHE_H

# include "utils/pair.h"

# define VAR_CACHE_PATH		"path"
# define VAR_CACHE_PWD		"pwd"

typedef struct s_var_cache
{
	t_pair	*path;
	t_pair	*pwd;

}	t_var_cache;

#endif
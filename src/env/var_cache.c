/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cache.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:53:33 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 15:56:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "env/var_cache.h"
#include "libft.h"

bool	var_is_in_cache(const char * var_name)
{
	if (ft_strcmp(VAR_CACHE_PATH, var_name) == 0)
		return (true);
	if (ft_strcmp(VAR_CACHE_PWD, var_name) == 0)
		return (true);
	return (false);
}
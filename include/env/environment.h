/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:00:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/16 21:04:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "libft.h"
# include "utils/pair.h"
# include "env/var_cache.h"

typedef struct s_environment
{
	t_list		*vars;
	t_var_cache	var_cache;
	
} t_environment;

//env/environment.c
bool	env_load(t_environment *env, const char **main_env);

//env/env_var_getter.c
bool	env_get(t_environment env, const char *key, char **value);

//env/env_utils.c
t_environment	env_new(void);
void			env_init(t_environment *env);
void			env_destroy(t_environment *env);
void			env_debug(t_environment env);



#endif
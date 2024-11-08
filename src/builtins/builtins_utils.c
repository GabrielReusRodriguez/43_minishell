/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:59:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:35:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

bool	is_builtin(const char *cmd)
{
	if (ft_strcmp(BUILTIN_CD, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_DECLARE, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_ECHO, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_ENV, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_EXIT, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_EXPORT, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_PWD, cmd) == 0)
		return (true);
	if (ft_strcmp(BUILTIN_UNSET, cmd) == 0)
		return (true);
	return (false);
}

bool	execute_builtin(const char *cmd, t_minishell *shell)
{
	if (ft_strcmp(BUILTIN_ENV, cmd)  == 0)
		builtin_env(NULL, shell);
	if (ft_strcmp(BUILTIN_EXIT, cmd) == 0)
		builtin_exit(NULL, shell);
	if (ft_strcmp(BUILTIN_EXPORT, cmd) == 0)
		builtin_export(NULL, shell);
	return (true);
}
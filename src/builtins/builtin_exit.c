/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:29:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 21:42:04 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

bool	builtin_exit(char **params, t_minishell *shell)
{
	(void)params;
	shell->run = false;
	shell->last_status = EXIT_SUCCESS;
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:27:41 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 00:39:25 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"

static void	builtin_env_print_var(t_pair pair)
{
	ft_putstr_fd("declare -x ",STDOUT_FILENO);

	ft_putstr_fd(pair.key,STDOUT_FILENO);
	ft_putstr_fd("=\"", STDOUT_FILENO);
	ft_putstr_fd(pair.value, STDOUT_FILENO);
	ft_putendl_fd("\"", STDOUT_FILENO);
}

bool	builtin_export(char **params, t_minishell *shell)
{
	t_list	*node;
	t_pair	*pair;

	(void)params;
	node = shell->env.vars;
	while (node != NULL)
	{
		pair = (t_pair *)node->content;
		builtin_env_print_var(*pair);
		node = node->next;
	}
	return (true);
}
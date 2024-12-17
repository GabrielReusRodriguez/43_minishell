/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:45:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/17 22:24:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"
#include "env/environment.h"
#include "utils/pair.h"


static bool	pair_to_string(t_pair  *pair, char **string)
{
	char	*key_value;
	char	*aux;

	aux = ft_strjoin(pair->key, "=");
	if (aux == NULL)
		return (ft_err_errno(NULL), false);
	key_value = ft_strjoin(aux, pair->value);
	free(aux);
	if (key_value == NULL)
		return (ft_err_errno(NULL), false);
	*string = key_value;
	return (true);
}

bool	env_to_char_ptr(t_minishell *shell, char ***envp)
{
	char	**env;
	int		num_words;
	t_list	*node;
	t_pair	*var;
	

	env = NULL;
	num_words = ft_lstsize(shell->env.vars);
	env = (char **)malloc(num_words*sizeof(char *));
	if (env == NULL)
		return (ft_err_errno(NULL), false);
	node = shell->env.vars;
	num_words = 0;
	while(node != NULL)
	{
		var = (t_pair *)node->content;
		if (!pair_to_string(var, &env[num_words]))
		{
			ft_ptr_free_dchar_ptr(env);
			return (false);
		}
		node = node->next;
	}
	*envp= env;
	return (true);
}
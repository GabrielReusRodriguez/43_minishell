/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:55:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 21:19:05 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cmd.h"
#include "libft.h"

static int	count_params(t_cmd *cmd)
{
	t_list *node;
	int		num;

	num = 0;
	node = cmd->args;
	while (node != NULL)
	{
		num++;
		node = node->next;
	}
	return (num);
}

static bool	get_memory(int num, char **str_params)
{
	str_params = (char **)malloc((num + 1) * sizeof(char *));
	if (str_params == NULL)
		return (ft_err_errno(NULL), false);
	return (true);
}

static	void	free_memory(int num, char **str_params)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free (str_params[i]);
		i++;
	}
	free (str_params);
}

bool	cmd_export_params(t_cmd *cmd, char **str_params)
{
	t_list	*node;
	int		num;
	int		i;

	num = count_params(cmd);
	if (!get_memory(num, str_params))
		return (false);
	i = 0;
	node = cmd->args;
	while (node != NULL)
	{
		str_params[i] = ft_strdup(node->content);
		if (str_params[i] == NULL)
		{
			free_memory(i, str_params);
			return (ft_err_errno(NULL), false);
		}
		i++;
		node = node->next;
	}
	str_params[num] = NULL;
	return (true);
}
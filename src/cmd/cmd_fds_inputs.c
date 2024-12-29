/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:28:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/29 18:53:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cmd.h"
#include "redirection.h"
#include "fd.h"

bool	treat_in_redirection(t_redirection *redir)
{
	if (redir->type == REDIRECT_IN_FILE)
	{
		
	}
	if (redir->type == REDIRECT_IN_HEREDOC)
	{

	}
	if (redir->type == REDIRECT_IN_HERESTRING)
	{

	}
}

// Cada nodo de la lista de redirecciones es del tipo : 	t_redirection	*redirection;
bool	cmd_open_redir_inputs(t_cmd *cmd, t_minishell *shell)
{
	t_list			*node;
	t_redirection	*redir;
	int				last_redirection;

	last_redirection = FD_NONE;
	node = cmd->input_redirections;
	while(node != NULL)
	{
		redir = (t_redirection *)redir;
		if (!treat_in_redirection(redir))
			return (false);
		node = node->next;
	}
	return (true);
}
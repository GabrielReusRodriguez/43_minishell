/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_fds_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:28:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/29 22:37:47 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "minishell.h"
#include "cmd.h"
#include "redirection.h"
#include "fd.h"
#include "path.h"

static bool	treat_file_redir(t_cmd *cmd, t_redirection *redir)
{
	t_path_types	type;
	int				fd;

	if (!path_check_mask(redir->file, F_OK | R_OK, true))
		return (false);
	if (!path_get_type(redir->file, &type, true))
		return (false);
	if (type != PATH_TYPE_FILE)
		return (ft_err_error("Is a directory"), true);
	fd = open(redir->file, O_RDONLY);
	if (fd < 0)
		return (ft_err_errno(NULL), false);
	cmd->fd_in = fd;
	return (true);

}

static bool	treat_in_redirection(t_cmd *cmd, t_redirection *redir)
{
	if (redir->type == REDIRECT_IN_FILE)
		return (treat_file_redir(cmd, redir));
	if (redir->type == REDIRECT_IN_HEREDOC)
	{

	}
	if (redir->type == REDIRECT_IN_HERESTRING)
	{

	}
	return (true);
}

// Cada nodo de la lista de redirecciones es del tipo : 	t_redirection	*redirection;
bool	cmd_open_redir_inputs(t_cmd *cmd)
{
	t_list			*node;
	t_redirection	*redir;

	node = cmd->input_redirections;
	while(node != NULL)
	{
		if (cmd->fd_in != FD_NONE)
		{
			if(!fd_close(cmd->fd_out))
				return (false);
		}
		redir = (t_redirection *)node->content;
		if (!treat_in_redirection(cmd, redir))
			return (false);
		node = node->next;
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:20:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/15 22:59:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "minishell.h"
#include "cmd.h"
#include "env/environment.h"
#include "path.h"

/*
bool	env_get_var(t_environment env, const char *key, char **value)
*/
static bool	get_pathname(t_minishell *shell, t_cmd *cmd, char **pathname)
{
	char	*path;
	char	**folders;
	char	*cmd_path;
	int		i;

	*pathname = NULL;
	if (path_check_mask(cmd->executable, F_OK | X_OK, false))
	{
		*pathname = ft_strdup(cmd->executable);
		return (true);
	}
	if (env_get_var(shell->env, "PATH", &path))
		return (false);
	folders = ft_split(path, ';');
	if (folders == NULL)
	{
		free(path);
		return (ft_err_errno(NULL), false);
	}
	i = 0;
	while(folders[i] != NULL)
	{
		cmd_path = ft_strjoin(folders[i], cmd->executable);
		if (cmd_path == NULL)
		{
			free(path);
			ft_ptr_free_dchar_ptr(folders);
			return(ft_err_errno(NULL), false);
		}
		if (path_check_mask(cmd_path, F_OK | X_OK, false))
		{
			*pathname = cmd_path;
			break;
		}
		free (cmd_path);
		i++;
	}
	free (path);
	ft_ptr_free_dchar_ptr(folders);
	return (true);
}

/*
int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);
*/
bool	executor_execve(t_minishell *shell, t_cmd *cmd)
{
	char	*pathname;
	char	**args;
	char	**envp;

	
	if (execve(pathname, args, envp) < 0)
		return (ft_err_errno(NULL), false);
}
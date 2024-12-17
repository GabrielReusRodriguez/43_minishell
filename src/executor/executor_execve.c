/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:20:07 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/17 22:27:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "minishell.h"
#include "cmd.h"
#include "env/environment.h"
#include "path.h"


/*
int execve(const char *pathname, char *const _Nullable argv[],
                  char *const _Nullable envp[]);
*/
bool	executor_execve(t_minishell *shell, t_cmd *cmd)
{
	char	*pathname;
	char	**args;
	char	**envp;

	args = NULL;
	envp = NULL;
	if (!path_get_pathname(shell, cmd, &pathname))
		return (false);
	if (!cmd_export_params(cmd, &args))
		return (false);
	if (!env_to_char_ptr(shell, &envp))
		return (false);
	if (execve(pathname, args, envp) < 0)
	{
		ft_ptr_free_dchar_ptr(envp);
		ft_ptr_free_dchar_ptr(args);
		free (pathname);
		ft_err_errno(NULL);
		exit(EXIT_FAILURE);
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:27:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/12 20:26:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "cmd.h"

# define BUILTIN_EXIT		"exit"
# define BUILTIN_CD			"cd"
# define BUILTIN_ECHO		"echo"
# define BUILTIN_EXPORT		"export"
# define BUILTIN_DECLARE	"declare"
# define BUILTIN_PWD		"pwd"
# define BUILTIN_UNSET		"unset"
# define BUILTIN_ENV		"env"

//builtins/builtins_utils.c
bool	is_builtin(t_cmd *cmd);
bool	execute_builtin(t_cmd *cmd, t_minishell *shell);
int		builtin_count_params(char **params);

//builtins/builtin_exit.c
bool	builtin_exit(char **params, t_minishell *shell, t_cmd *cmd);

//builtins/builtin_env.c
bool	builtin_env(char **params, t_minishell *shell, t_cmd *cmd);

//builtin/builtin_export.c
bool	builtin_export(char **params, t_minishell *shell, t_cmd *cmd);

/*
//builtins/builtins_utils.c
bool	is_builtin(const char *cmd);
bool	execute_builtin(const char *cmd, t_minishell *shell);

//builtins/builtin_exit.c
bool	builtin_exit(char **params, t_minishell *shell);

//builtins/builtin_env.c
bool	builtin_env(char **params, t_minishell *shell);

//builtin/builtin_export.c
bool	builtin_export(char **params, t_minishell *shell);
*/
#endif
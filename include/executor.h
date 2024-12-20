/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:51:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/17 21:18:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>

# include "job.h"
# include "cmd.h"
# include "minishell.h"

bool	executor_execute_job(t_minishell *shell, t_job *job);
bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, bool is_pipeline);

//executor/executor_logic.c
bool	executor_execute_logic(t_minishell *shell, t_cmd *cmd);

//executor/executor_execve.c
bool	executor_execve(t_minishell *shell, t_cmd *cmd);

#endif
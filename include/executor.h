/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:51:04 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 20:27:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <sys/types.h>

# include "job.h"
# include "cmd.h"
# include "minishell.h"

bool	executor_execute_job(t_minishell *shell, t_job *job);
bool	executor_execute_cmd(t_minishell *shell, t_cmd *cmd, \
			bool is_unique_cmd);

#endif
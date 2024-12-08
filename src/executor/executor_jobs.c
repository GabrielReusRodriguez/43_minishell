/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/08 20:33:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <sys/types.h>

#include "executor.h"
#include "job.h"
#include "cmd.h"
#include "libft.h"

#include <stdio.h>

static	bool	is_unique_cmd(t_job *job)
{
	if (job == NULL)
		return true;
	if (ft_lstsize(job->cmds) > 1)
		return (false);
	return (true);
}

static bool	executor_jobs_loop(t_minishell *shell, t_cmd *cmd, \
				bool *is_pipeline, bool unique_cmd)
{
	printf("Inicio loop\n");
	executor_execute_cmd(shell, cmd, unique_cmd);
	printf("Fin exec loop\n");
	if (cmd->type == CMD_TYPE_PIPE)
	{
		*is_pipeline = true;
		//pipe lining, pùsh at pid list and next command..
	}
	else
	{
		//waits...
		*is_pipeline = false;
	}
	return (true);
}

bool	executor_execute_job(t_minishell *shell, t_job *job)
{
	t_list	*node;
	bool	is_pipeline;
	bool	unique_cmd;

	node = job->cmds;
	is_pipeline = false;
	unique_cmd = is_unique_cmd(job);
	while (node != NULL)
	{
		executor_jobs_loop(shell, (t_cmd *)node->content, &is_pipeline, unique_cmd);
		node = node->next;
	}
	return (true);
}
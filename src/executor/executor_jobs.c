/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:34:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/11 21:43:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "executor.h"
#include "job.h"
#include "cmd.h"
#include "libft.h"

#include <stdio.h>


static	unsigned char	translate_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	if (WIFSTOPPED(status))
		return (128 + WSTOPSIG(status));
	return (status);
}

static	bool	wait_status(t_job *job, t_minishell *shell)
{
	t_list	*node;
	t_cmd	*cmd;
	pid_t	pid;
	int		status;
	
	node = job->cmds;
	while(node != NULL)
	{
		cmd = (t_cmd *)node->content;
		pid = waitpid(cmd->pid, &cmd->return_value,0);
		if (pid < 0)
			return (ft_err_errno(NULL), false);
		status = cmd->return_value;
		node = node->next;
	}
	shell->last_status = translate_status(status);
	return (true);
}

static bool	executor_jobs_loop(t_minishell *shell, t_cmd *cmd, \
				bool *is_pipeline)
{
	executor_execute_cmd(shell, cmd, *is_pipeline);
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

	node = job->cmds;
	is_pipeline = false;
	while (shell->run && node != NULL)
	{
		executor_jobs_loop(shell, (t_cmd *)node->content, &is_pipeline);
		node = node->next;
	}
	return(wait_status(job, shell));
}
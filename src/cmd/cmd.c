/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:51:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 23:06:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "tokenizer/token.h"
#include "tokenizer/tokenizer.h"

t_cmd	cmd_new(void)
{
	t_cmd	cmd;
	
	cmd_init(&cmd);
	return (cmd);
}

void	cmd_init(t_cmd *cmd)
{
	cmd->input_redirections = NULL;
	cmd->executable = NULL;
	cmd->args = NULL;
	cmd->output_redirections = NULL;	
}

void	cmd_destroy(t_cmd *cmd)
{
	if (cmd->input_redirections != NULL)
		ft_lstclear(&cmd->input_redirections, tokenizer_clear_list_node);
	if (cmd->executable != NULL)
		token_destroy(cmd->executable);
	if (cmd->args != NULL)
		ft_lstclear(&cmd->args, tokenizer_clear_list_node);
	if (cmd->output_redirections != NULL)
		ft_lstclear(&cmd->output_redirections, tokenizer_clear_list_node);
}
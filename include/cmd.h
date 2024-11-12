/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:34:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/09 22:54:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "libft.h"
# include "tokenizer/token.h"

typedef struct s_cmd
{
	t_list	*input_redirections;
	t_token	*executable;
	t_list	*args;
	t_list	*output_redirections;
}	t_cmd;

void	cmd_init(t_cmd *cmd);
t_cmd	cmd_new(void);
void	cmd_destroy(t_cmd *cmd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:25:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/04 20:59:35 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdlib.h>

typedef enum e_shell_mode
{
	INTERACTIVE,
	STANDALONE
} t_shell_mode;

typedef struct s_minishell
{
	bool			run;
	unsigned char	last_status;
	char			*cmd;
	t_shell_mode	mode;

}	t_minishell;

bool	minishell_init(t_minishell *shell);
bool	minishell_destroy(t_minishell *shell);
bool	minishell_loop(t_minishell *shell);

#endif
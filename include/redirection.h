/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:48:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/04 19:16:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

typedef enum e_redirect_type
{
	REDIRECT_NONE,
	REDIRECT_IN_FILE,
	REDIRECT_IN_HEREDOC,
	REDIRECT_OUT_APPEND,
	REDIRECT_OUT_ADD

}	t_redirect_type;


typedef struct s_redirection
{
	t_redirect_type	type;
	char	*lim_here_doc;
	char	*file;
	char	*here_doc;
}	t_redirection;

void	redirect_init(t_redirection *redir);
bool	redirect_new(t_redirection	**redirect);
void	redirect_destroy(t_redirection *redir);
bool	redirect_parse(t_list **node, t_redirection **redir);

#endif
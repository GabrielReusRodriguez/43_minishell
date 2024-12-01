/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:48:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/01 22:54:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

typedef enum e_redirect_type
{
	REDIRECT_IN_FILE,
	REDIRECT_IN_HEREDOC,
	REDIRECT_OUT_APPEND,
	REDIRECT_OUT_ADD

}	t_redirect_type;


typedef struct s_redirection
{
	t_redirect_type	type;
	char	*lim;
	char	*file;
}	t_redirection;


#endif
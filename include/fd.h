/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:43:53 by gabriel           #+#    #+#             */
/*   Updated: 2024/11/08 10:47:48 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FD_H
# define FD_H

bool	fd_copy(int oldfd);
bool	fd_replace(int oldfd, int newfd);
bool	fd_close(int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:31:42 by gabriel           #+#    #+#             */
/*   Updated: 2024/12/15 22:43:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

bool	path_can_exec(const char *path,  bool verbose);
bool	path_can_read(const char *path, bool verbose);
bool	path_can_write(const char *path, bool verbose);
bool	path_can_exists(const char *path, bool verbose);
bool	path_check_mask(const char *path, int mask, bool verbose);

#endif
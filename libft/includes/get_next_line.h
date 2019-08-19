/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:03:02 by mgayduk           #+#    #+#             */
/*   Updated: 2018/04/28 16:20:24 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define GNL_BUFF_SIZE 16
# define GNL_ERROR -1
# define GNL_FILE_END 0

int get_next_line(const int fd, char **line);

#endif

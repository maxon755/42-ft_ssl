/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:26:44 by maks              #+#    #+#             */
/*   Updated: 2019/08/12 11:11:49 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "ft_md5.h"
# include "ft_sha256.h"

# define ALGO_QTY 2

# define DIGEST 1

typedef int	(*t_hash_func)(int, char *const *argv);

typedef struct	s_hash_algo
{
	char		*name;
	int			category;
	t_hash_func	func;
}				t_hash_algo;

extern const	t_hash_algo g_algo_list[ALGO_QTY];

void			print_error_message(char *wrong_name);
void			print_help_message();

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:59:03 by maks              #+#    #+#             */
/*   Updated: 2019/07/31 11:19:38 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

/*
** The behavior of ft_getopt is the same as getopt from libc.
*/

typedef struct		s_flag
{
	int				symbol;
	int				valid;
	int				is_last_symbol;
	char			*str;
	int				is_multi_symbol;
	int				has_arg;
}					t_flag;

extern int g_flag_position;

int					ft_getopt(int argc, char *const *argv, const char *opstr);
t_flag				*parse_flag(char *const flag_str, const char *opt_str);
void				print_flag(t_flag *flag);
void				set_global_vars(int optind_inc, int g_flag_position);
int					is_flag(char *const str);

#endif

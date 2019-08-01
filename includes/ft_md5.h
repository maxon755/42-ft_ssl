/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:25:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/01 17:04:41 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"

typedef struct		s_md5_flags
{
	int 			p;
	int				q;
	int				r;
	int				s;
	char			*s_arg;
	int				wrong_argument;
}					t_md5_flags;

extern t_md5_flags md5_flags;

typedef struct		s_md5_message
{
	char 			*init_str;
	unsigned int	init_length;
	unsigned int	init_length_bit;
	unsigned int	padding_length_bit;
}					t_md5_message;

int md5(int argc, char * const *argv);

void parse_flags(int argc, char * const *argv);
void prepare_message(t_md5_message *message);
unsigned int get_padding_size(unsigned int bit_length);

#endif
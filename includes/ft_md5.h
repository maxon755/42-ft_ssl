/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:25:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/02 15:10:57 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"

#define BYTES_FOR_SIZE 8

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
	uint64_t		init_length;
	uint64_t		init_length_bit;
	unsigned int	padding_length;
	unsigned char	*prepared;
	uint64_t		result_length;
}					t_md5_message;

int md5(int argc, char * const *argv);

void parse_flags(int argc, char * const *argv);
void prepare_message(t_md5_message *message);
unsigned int get_padding_size(unsigned int bit_length);

#endif
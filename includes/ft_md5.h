/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:25:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/08 18:55:05 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

# define BYTES_FOR_SIZE 8
# define MD5_BLOCK_SIZE 64
# define MD5_HASH_SIZE 16
# define ROL32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

# define S11 7
# define S12 12
# define S13 17
# define S14 22
# define S21 5
# define S22 9
# define S23 14
# define S24 20
# define S31 4
# define S32 11
# define S33 16
# define S34 23
# define S41 6
# define S42 10
# define S43 15
# define S44 21

# define F(x, y, z) (((x) & (y)) | (~(x) & (z)))
# define G(x, y, z)	(((x) & (z)) | ((y) & ~(z)))
# define H(x, y, z)	((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | ~(z)))

# define FF(a, b, c, d, x, s, k) a += F(b, c, d) + (x) + (k), a = ROL32(a, s) + (b)
# define GG(a, b, c, d, x, s, k) a += G(b, c, d) + (x) + (k), a = ROL32(a, s) + (b)
# define HH(a, b, c, d, x, s, k) a += H(b, c, d) + (x) + (k), a = ROL32(a, s) + (b)
# define II(a, b, c, d, x, s, k) a += I(b, c, d) + (x) + (k), a = ROL32(a, s) + (b)

typedef struct		s_md5_flags
{
	int				p;
	int				q;
	int				r;
	int				s;
	char			*s_arg;
	int				wrong_argument;
}					t_md5_flags;

extern t_md5_flags md5_flags;

typedef struct		s_md5_message
{
	char 			*source;
	uint64_t		init_length;
	uint64_t		source_size;
	uint64_t		chunk_size;
	unsigned int	padding_length;
	unsigned char	*prepared;
	uint64_t		result_length;
}					t_md5_message;

typedef struct		s_md5_data
{
	uint32_t		x[16];
	uint32_t		*hash_buffer;
	uint32_t		buffer[4];
}					t_md5_data;

int 				md5(int argc, char * const *argv);

void 				parse_flags(int argc, char * const *argv);
t_md5_data			*init_data(void);
t_md5_message		*init_string_message(char * str);
void				hash_string(char * const str);
void 				hash_file(char *filename);
void				hash_input_stream(void);
void				compute_hash(t_md5_data *data);
unsigned int		get_padding_size(uint64_t length);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:25:50 by maks              #+#    #+#             */
/*   Updated: 2019/08/10 14:00:51 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define MD5_BYTES_FOR_SIZE 8
# define MD5_BLOCK_SIZE 64
# define MD5_FILE_BUFFER MD5_BLOCK_SIZE * 16
# define MD5_DIGEST_SIZE 16

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

# define FF(a, b, c, d, x, s, k) a += F(b, c, d) + x + k, a = ROL32(a, s) + b
# define GG(a, b, c, d, x, s, k) a += G(b, c, d) + x + k, a = ROL32(a, s) + b
# define HH(a, b, c, d, x, s, k) a += H(b, c, d) + x + k, a = ROL32(a, s) + b
# define II(a, b, c, d, x, s, k) a += I(b, c, d) + x + k, a = ROL32(a, s) + b

typedef struct		s_md5_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_md5_flags;

extern t_md5_flags g_md5_flags;

typedef struct		s_md5_context
{
	unsigned char	buffer[MD5_BLOCK_SIZE];
	uint32_t		state[4];
	uint64_t		source_size_bits;
}					t_md5_context;

int					md5(int argc, char *const *argv);
void				md5_hash_file(char *file_name);
void				md5_hash_string(char *string);
void				md5_hash_stdin(void);
void				md5_init(t_md5_context *context);
void				md5_update(
						t_md5_context *context,
						unsigned char *input,
						unsigned int input_size);
void				md5_finish(
						unsigned char digest[MD5_DIGEST_SIZE],
						t_md5_context *context);
void				md5_transform(uint32_t state[4], unsigned char *block);
void				md5_print(
						unsigned char digest[MD5_DIGEST_SIZE],
						char *source,
						ft_bool is_file);
void				md5_print_digest(unsigned char digest[MD5_DIGEST_SIZE]);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:45:18 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 12:37:10 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA224_H
# define FT_SHA224_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA224_BYTES_FOR_SIZE	8
# define SHA224_BLOCK_SIZE 		64
# define SHA224_BUFFER_SIZE		SHA224_BLOCK_SIZE
# define SHA224_DIGEST_SIZE		32
# define SHA224_STATE_SIZE		8
# define SHA224_FILE_BUFFER 	(SHA224_BLOCK_SIZE * 16)

# define ROL32(x, n) (FT_ROTL(x, n, 32))
# define ROR32(x, n) (FT_ROTR(x, n, 32))

# define SHA224_CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define SHA224_MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA224_SIGMA1(x) (ROR32(x, 2) ^ ROR32(x, 13) ^ ROR32(x, 22))
# define SHA224_SIGMA2(x) (ROR32(x, 6) ^ ROR32(x, 11) ^ ROR32(x, 25))
# define SHA224_SIGMA3(x) (ROR32(x, 7) ^ ROR32(x, 18) ^ SHR(x, 3))
# define SHA224_SIGMA4(x) (ROR32(x, 17) ^ ROR32(x, 19) ^ SHR(x, 10))

# define SHA224_A (temp_state[0])
# define SHA224_B (temp_state[1])
# define SHA224_C (temp_state[2])
# define SHA224_D (temp_state[3])
# define SHA224_E (temp_state[4])
# define SHA224_F (temp_state[5])
# define SHA224_G (temp_state[6])
# define SHA224_H (temp_state[7])

typedef struct		s_sha224_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_sha224_flags;

extern t_sha224_flags g_sha224_flags;

typedef struct		s_sha224_context
{
	unsigned char	buffer[SHA224_BLOCK_SIZE];
	uint32_t		state[SHA224_STATE_SIZE];
	uint64_t		source_size_bits;
}					t_sha224_context;

int					sha224(int argc, char *const *argv);
void				sha224_hash_string(char *string);
void				sha224_hash_file(char *file_name);
void				sha224_hash_stdin(void);
void				sha224_init(t_sha224_context *context);
void				sha224_update(
						t_sha224_context *context,
						unsigned char *input,
						unsigned int input_size);
void				sha224_finish(
						unsigned char digest[SHA224_DIGEST_SIZE],
						t_sha224_context *context);
void				sha224_transform(
						uint32_t state[SHA224_STATE_SIZE],
						unsigned char block[SHA224_BLOCK_SIZE]);
void				sha224_print(
						unsigned char digest[SHA224_DIGEST_SIZE],
						char *source,
						ft_bool is_file);
void				sha224_print_digest(
						unsigned char digest[SHA224_DIGEST_SIZE]);

#endif

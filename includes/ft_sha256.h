/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:45:18 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 16:09:13 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA256_BYTES_FOR_SIZE	8
# define SHA256_BLOCK_SIZE 		64
# define SHA256_BUFFER_SIZE		SHA256_BLOCK_SIZE
# define SHA256_DIGEST_SIZE		32
# define SHA256_STATE_SIZE		8
# define SHA256_FILE_BUFFER 	(SHA256_BLOCK_SIZE * 16)

# define ROL32(x, n) (FT_ROTL(x, n, 32))
# define ROR32(x, n) (FT_ROTR(x, n, 32))

# define SHA256_CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define SHA256_MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA256_SIGMA1(x) (ROR32(x, 2) ^ ROR32(x, 13) ^ ROR32(x, 22))
# define SHA256_SIGMA2(x) (ROR32(x, 6) ^ ROR32(x, 11) ^ ROR32(x, 25))
# define SHA256_SIGMA3(x) (ROR32(x, 7) ^ ROR32(x, 18) ^ SHR(x, 3))
# define SHA256_SIGMA4(x) (ROR32(x, 17) ^ ROR32(x, 19) ^ SHR(x, 10))

# define SHA256_A (temp_state[0])
# define SHA256_B (temp_state[1])
# define SHA256_C (temp_state[2])
# define SHA256_D (temp_state[3])
# define SHA256_E (temp_state[4])
# define SHA256_F (temp_state[5])
# define SHA256_G (temp_state[6])
# define SHA256_H (temp_state[7])

typedef struct		s_sha256_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_sha256_flags;

extern t_sha256_flags g_sha256_flags;

typedef struct		s_sha256_context
{
	unsigned char	buffer[SHA256_BLOCK_SIZE];
	uint32_t		state[SHA256_STATE_SIZE];
	uint64_t		source_size_bits;
}					t_sha256_context;

int					sha256(int argc, char *const *argv);
void				sha256_hash_string(char *string);
void				sha256_hash_file(char *file_name);
void				sha256_hash_stdin(void);
void				sha256_init(t_sha256_context *context);
void				sha256_update(
						t_sha256_context *context,
						unsigned char *input,
						unsigned int input_size);
void				sha256_finish(
						unsigned char digest[SHA256_DIGEST_SIZE],
						t_sha256_context *context);
void				sha256_transform(
						uint32_t state[SHA256_STATE_SIZE],
						unsigned char block[SHA256_BLOCK_SIZE]);
void				sha256_print(
						unsigned char digest[SHA256_DIGEST_SIZE],
						char *source,
						t_bool is_file);
void				sha256_print_digest(
						unsigned char digest[SHA256_DIGEST_SIZE]);

#endif

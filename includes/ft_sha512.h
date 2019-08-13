/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:45:18 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 16:36:07 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA512_BYTES_FOR_SIZE	16
# define SHA512_BLOCK_SIZE 		128
# define SHA512_BUFFER_SIZE		SHA512_BLOCK_SIZE
# define SHA512_DIGEST_SIZE		64
# define SHA512_STATE_SIZE		8
# define SHA512_FILE_BUFFER 	(SHA512_BLOCK_SIZE * 16)

# define ROL64(x, n) (FT_ROTL(x, n, 64))
# define ROR64(x, n) (FT_ROTR(x, n, 64))

# define SHA512_CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define SHA512_MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA512_BSIG0(x) (ROR64(x, 28) ^ ROR64(x, 34) ^ ROR64(x, 39))
# define SHA512_BSIG1(x) (ROR64(x, 14) ^ ROR64(x, 18) ^ ROR64(x, 41))
# define SHA512_SSIG0(x) (ROR64(x, 1) ^ ROR64(x, 8) ^ SHR(x, 7))
# define SHA512_SSIG1(x) (ROR64(x, 19) ^ ROR64(x, 61) ^ SHR(x, 6))

# define SHA512_A (temp_state[0])
# define SHA512_B (temp_state[1])
# define SHA512_C (temp_state[2])
# define SHA512_D (temp_state[3])
# define SHA512_E (temp_state[4])
# define SHA512_F (temp_state[5])
# define SHA512_G (temp_state[6])
# define SHA512_H (temp_state[7])

typedef uint64_t t_sha512_word;

typedef struct		s_sha512_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_sha512_flags;

extern t_sha512_flags g_sha512_flags;

typedef struct		s_sha512_context
{
	unsigned char	buffer[SHA512_BLOCK_SIZE];
	t_sha512_word	state[SHA512_STATE_SIZE];
	__uint128_t		source_size_bits;
}					t_sha512_context;

int					sha512(int argc, char *const *argv);
void				sha512_hash_string(char *string);
void				sha512_hash_file(char *file_name);
void				sha512_hash_stdin(void);
void				sha512_init(t_sha512_context *context);
void				sha512_update(
						t_sha512_context *context,
						unsigned char *input,
						unsigned int input_size);
void				sha512_finish(
						unsigned char digest[SHA512_DIGEST_SIZE],
						t_sha512_context *context);
void				sha512_transform(
						uint64_t state[SHA512_STATE_SIZE],
						unsigned char block[SHA512_BLOCK_SIZE]);
void				sha512_print(
						unsigned char digest[SHA512_DIGEST_SIZE],
						char *source,
						ft_bool is_file);
void				sha512_print_digest(
						unsigned char digest[SHA512_DIGEST_SIZE]);

#endif

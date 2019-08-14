/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:45:18 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 16:09:13 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA384_H
# define FT_SHA384_H

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA384_BYTES_FOR_SIZE	16
# define SHA384_BLOCK_SIZE 		128
# define SHA384_BUFFER_SIZE		SHA384_BLOCK_SIZE
# define SHA384_DIGEST_SIZE		64
# define SHA384_STATE_SIZE		8
# define SHA384_FILE_BUFFER 	(SHA384_BLOCK_SIZE * 16)

# define ROL64(x, n) (FT_ROTL(x, n, 64))
# define ROR64(x, n) (FT_ROTR(x, n, 64))

# define SHA384_CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define SHA384_MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHA384_BSIG0(x) (ROR64(x, 28) ^ ROR64(x, 34) ^ ROR64(x, 39))
# define SHA384_BSIG1(x) (ROR64(x, 14) ^ ROR64(x, 18) ^ ROR64(x, 41))
# define SHA384_SSIG0(x) (ROR64(x, 1) ^ ROR64(x, 8) ^ SHR(x, 7))
# define SHA384_SSIG1(x) (ROR64(x, 19) ^ ROR64(x, 61) ^ SHR(x, 6))

# define SHA384_A (temp_state[0])
# define SHA384_B (temp_state[1])
# define SHA384_C (temp_state[2])
# define SHA384_D (temp_state[3])
# define SHA384_E (temp_state[4])
# define SHA384_F (temp_state[5])
# define SHA384_G (temp_state[6])
# define SHA384_H (temp_state[7])

typedef uint64_t t_sha384_word;

typedef struct		s_sha384_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_sha384_flags;

extern t_sha384_flags g_sha384_flags;

typedef struct		s_sha384_context
{
	unsigned char	buffer[SHA384_BLOCK_SIZE];
	t_sha384_word	state[SHA384_STATE_SIZE];
	__uint128_t		source_size_bits;
}					t_sha384_context;

int					sha384(int argc, char *const *argv);
void				sha384_hash_string(char *string);
void				sha384_hash_file(char *file_name);
void				sha384_hash_stdin(void);
void				sha384_init(t_sha384_context *context);
void				sha384_update(
						t_sha384_context *context,
						unsigned char *input,
						unsigned int input_size);
void				sha384_finish(
						unsigned char digest[SHA384_DIGEST_SIZE],
						t_sha384_context *context);
void				sha384_transform(
						uint64_t state[SHA384_STATE_SIZE],
						unsigned char block[SHA384_BLOCK_SIZE]);
void				sha384_print(
						unsigned char digest[SHA384_DIGEST_SIZE],
						char *source,
						t_bool is_file);
void				sha384_print_digest(
						unsigned char digest[SHA384_DIGEST_SIZE]);

#endif

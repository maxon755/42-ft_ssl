/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_256.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:13:00 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/11 14:10:19 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA_256_BYTES_FOR_SIZE 8
# define SHA_256_BLOCK_SIZE 64
# define SHA_256_DIGEST_SIZE 32
# define SHA_256_STATE_SIZE 8

typedef struct		s_sha_256_flags
{
	unsigned char	p:1;
	unsigned char	q:1;
	unsigned char	r:1;
	unsigned char	s:1;
}					t_sha_256_flags;

extern t_sha_256_flags g_sha_256_flags;

typedef struct		s_sha_256_context
{
	unsigned char	buffer[SHA_256_BLOCK_SIZE];
	uint32_t		state[SHA_256_STATE_SIZE];
	uint64_t		source_size_bits;
}					t_sha_256_context;

int					sha_256(int argc, char *const *argv);
void				sha_256_hash_string(char *string);
void				sha_256_init(t_sha_256_context *context);
void				sha_256_update(
						t_sha_256_context *context,
						unsigned char *input,
						unsigned int input_size);
void				sha_256_finish(
						unsigned char digest[SHA_256_DIGEST_SIZE],
						t_sha_256_context *context);
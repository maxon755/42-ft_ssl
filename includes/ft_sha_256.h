/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_256.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:13:00 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 17:29:59 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>

# define SHA_256_BLOCK_SIZE 64
# define SHA_256_DIGEST_SIZE 32

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
	uint32_t		state[8];
	uint64_t		source_size_bits;
}					t_sha_256_context;

void				md5_init(t_sha_256_context *context);
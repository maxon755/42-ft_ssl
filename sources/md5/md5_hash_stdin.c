/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:42:28 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/12 14:33:59 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags g_md5_flags;

void		md5_hash_stdin(void)
{
	unsigned int	byte_readed;
	t_md5_context	context;
	unsigned char	digest[MD5_DIGEST_SIZE];
	unsigned char	buffer[MD5_BLOCK_SIZE];

	md5_init(&context);
	while ((byte_readed = read(STDIN_FILENO, buffer, MD5_BLOCK_SIZE)) > 0)
	{
		md5_update(&context, buffer, byte_readed);
		if (g_md5_flags.p)
			write(STDOUT_FILENO, buffer, byte_readed);
	}
	md5_finish(digest, &context);
	md5_print_digest(digest);
	ft_putchar('\n');
}

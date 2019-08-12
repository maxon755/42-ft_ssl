/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash_stdin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:17:04 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/12 15:53:13 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

t_sha256_flags g_sha256_flags;

void		sha256_hash_stdin(void)
{
	unsigned int	byte_readed;
	t_sha256_context	context;
	unsigned char	digest[SHA256_DIGEST_SIZE];
	unsigned char	buffer[SHA256_BLOCK_SIZE];

	sha256_init(&context);
	while ((byte_readed = read(STDIN_FILENO, buffer, SHA256_BLOCK_SIZE)) > 0)
	{
		sha256_update(&context, buffer, byte_readed);
		if (g_sha256_flags.p)
			write(STDOUT_FILENO, buffer, byte_readed);
	}
	sha256_finish(digest, &context);
	sha256_print_digest(digest);
	ft_putchar('\n');
}
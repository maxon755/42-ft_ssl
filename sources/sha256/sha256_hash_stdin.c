/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash_stdin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:17:04 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/12 13:25:46 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

t_sha256_flags g_sha256_flags;

static char	*append_input(
		char *input,
		unsigned char buffer[SHA256_BLOCK_SIZE],
		unsigned int length)
{
	char *tmp_str;

	if (!input)
		input = ft_strnew(0);
	tmp_str = ft_strnew(length);
	ft_memcpy(tmp_str, buffer, length);
	input = ft_strjoin_m(input, tmp_str, FT_FREE_BOTH);
	return (input);
}

void		sha256_hash_stdin(void)
{
	unsigned int	byte_readed;
	t_sha256_context	context;
	unsigned char	digest[SHA256_DIGEST_SIZE];
	unsigned char	buffer[SHA256_BLOCK_SIZE];
	char			*input;

	input = NULL;
	sha256_init(&context);
	while ((byte_readed = read(STDIN_FILENO, buffer, SHA256_FILE_BUFFER)) > 0)
	{
		sha256_update(&context, buffer, byte_readed);
		if (g_sha256_flags.p)
			input = append_input(input, buffer, byte_readed);
	}
	sha256_finish(digest, &context);
	if (g_sha256_flags.p && input != NULL)
	{
		ft_printf("%s", input);
		free(input);
	}
	sha256_print_digest(digest);
	ft_putchar('\n');
}

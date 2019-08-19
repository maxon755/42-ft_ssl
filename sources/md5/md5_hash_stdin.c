/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:42:28 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/12 18:31:26 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags g_md5_flags;

static char	*append_input(
		char *input,
		unsigned char buffer[MD5_BLOCK_SIZE],
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

void		md5_hash_stdin(void)
{
	unsigned int	byte_readed;
	t_md5_context	context;
	unsigned char	digest[MD5_DIGEST_SIZE];
	unsigned char	buffer[MD5_BLOCK_SIZE];
	char			*input;

	input = NULL;
	md5_init(&context);
	while ((byte_readed = read(STDIN_FILENO, buffer, MD5_BLOCK_SIZE)) > 0)
	{
		md5_update(&context, buffer, byte_readed);
		if (g_md5_flags.p)
			input = append_input(input, buffer, byte_readed);
	}
	md5_finish(digest, &context);
	if (g_md5_flags.p && input != NULL)
	{
		ft_printf("%s", input);
		free(input);
	}
	md5_print_digest(digest);
	ft_putchar('\n');
}

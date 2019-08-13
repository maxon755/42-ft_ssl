/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:40:28 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/13 12:37:14 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

void	sha224_print_digest(unsigned char digest[SHA224_DIGEST_SIZE])
{
	unsigned int i;

	i = 0;
	while (i < SHA224_DIGEST_SIZE - 4)
	{
		ft_printf("%02x", digest[i + 3]);
		ft_printf("%02x", digest[i + 2]);
		ft_printf("%02x", digest[i + 1]);
		ft_printf("%02x", digest[i]);
		i += 4;
	}
}

void	sha224_print(
	unsigned char digest[SHA224_DIGEST_SIZE],
	char *source,
	ft_bool is_file)
{
	if (!g_sha224_flags.q && !g_sha224_flags.r)
	{
		if (is_file)
			ft_printf("SHA224 (%s) = ", source);
		else
			ft_printf("SHA224 (\"%s\") = ", source);
	}
	sha224_print_digest(digest);
	if (g_sha224_flags.r && !g_sha224_flags.q)
		is_file ? ft_printf(" %s", source) : ft_printf(" \"%s\"", source);
	ft_putchar('\n');
}

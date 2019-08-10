/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:40:28 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 13:59:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	md5_print_digest(unsigned char digest[MD5_DIGEST_SIZE])
{
	unsigned int i;

	i = 0;
	while (i < MD5_DIGEST_SIZE)
		ft_printf("%02x", digest[i++]);
}

void	md5_print(
	unsigned char digest[MD5_DIGEST_SIZE],
	char *source,
	ft_bool is_file)
{
	if (!g_md5_flags.q && !g_md5_flags.r)
	{
		if (is_file)
			ft_printf("MD5 (%s) = ", source);
		else
			ft_printf("MD5 (\"%s\") = ", source);
	}
	md5_print_digest(digest);
	if (g_md5_flags.r && !g_md5_flags.q)
		ft_printf(" %s", source);
	ft_putchar('\n');
}

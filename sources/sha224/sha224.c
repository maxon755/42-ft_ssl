/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:26:07 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 12:33:12 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

t_sha224_flags g_sha224_flags;

static void		handle_files(int argc, char *const *argv)
{
	int	i;

	i = optind;
	while (i < argc)
		sha224_hash_file(argv[i++]);
}

static int		print_usage(void)
{
	ft_printf("usage: sha224 [-pqr] [-s string] [files ...]\n");
	return (1);
}

int				sha224(int argc, char *const *argv)
{
	int	flag;

	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'p')
		{
			g_sha224_flags.p = 1;
			sha224_hash_stdin();
		}
		else if (flag == 'q')
			g_sha224_flags.q = 1;
		else if (flag == 'r')
			g_sha224_flags.r = 1;
		else if (flag == 's')
		{
			g_sha224_flags.s = 1;
			sha224_hash_string(optarg);
		}
		else if (flag == '?')
			return (print_usage());
	}
	if (!argv[optind] && !g_sha224_flags.s && !g_sha224_flags.p)
		sha224_hash_stdin();
	handle_files(argc, argv);
	return (0);
}

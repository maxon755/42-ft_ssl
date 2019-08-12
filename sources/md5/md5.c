/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/12 13:46:36 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags g_md5_flags;

static void		handle_files(int argc, char *const *argv)
{
	int	i;

	i = optind;
	while (i < argc)
		md5_hash_file(argv[i++]);
}

int				md5(int argc, char *const *argv)
{
	int	flag;

	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'p')
		{
			g_md5_flags.p = 1;
			md5_hash_stdin();
		}
		else if (flag == 'q')
			g_md5_flags.q = 1;
		else if (flag == 'r')
			g_md5_flags.r = 1;
		else if (flag == 's')
		{
			g_md5_flags.s = 1;
			md5_hash_string(optarg);
		}
		else if (flag == '?')
			return (1);
	}
	if (!argv[optind] && !g_md5_flags.s && !g_md5_flags.p)
		md5_hash_stdin();
	handle_files(argc, argv);
	return (0);
}

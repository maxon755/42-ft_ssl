/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/10 11:55:43 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags g_md5_flags;

int			md5(int argc, char *const *argv)
{
	int	flag;
	int	i;

	ft_printf("argc %i\n", argc);
	if (argc == 1)
	{
		g_md5_flags.p = 1;
		md5_hash_stdin();
	}
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
	i = optind;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		md5_hash_file(argv[i]);
		i++;
	}

	system("leaks ft_ssl");
	return (0);
}

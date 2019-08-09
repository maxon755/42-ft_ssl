/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/08 18:40:36 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags md5_flags;

int				md5(int argc, char * const *argv)
{
	int i;
	int flag;

	i = 0;
	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'p')
		{
			md5_flags.p = 1;
			hash_input_stream();
		}
		else if (flag == 'q')
			md5_flags.q = 1;
		else if (flag == 'r')
			md5_flags.r = 1;
		else if (flag == 's')
		{
			md5_flags.s = 1;
			hash_string(optarg);
		}
		else if (flag == '?')
			return (1);
		i++;
	}

	if (!i && !argv[optind])
	{
		ft_putendl("Ready to read from stdin");
		hash_input_stream();
	}

	i = optind;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		hash_file(argv[i++]);
	}

	return 0;
}
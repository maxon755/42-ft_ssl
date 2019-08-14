/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 17:07:19 by maks             ###   ########.fr       */
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

static int		print_usage(void)
{
	ft_printf("usage: md5 [-pqrh] [-s string] [files ...]\n"
		"       use -h for help\n");
	return (1);
}

static int		print_help(void)
{
	ft_printf("Message Digest 5\n"
		"usage: md5 [-pqrh] [-s string] [files ...]\n"
		"  -p, echo STDIN to STDOUT and append the checksum to STDOUT\n"
		"  -q, quiet mode\n"
		"  -r, reverse the format of the output\n"
		"  -s, print the sum of the given string\n"
		"  -h, help\n");
	return (0);
}

static void		handle_flag(int flag)
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
}

int				md5(int argc, char *const *argv)
{
	int	flag;

	while ((flag = ft_getopt(argc, argv, "hpqrs:")) != -1)
	{
		if (flag == '?')
			return (print_usage());
		else if (flag == 'h')
			return (print_help());
		handle_flag(flag);
	}
	if (!argv[optind] && !g_md5_flags.s && !g_md5_flags.p)
		md5_hash_stdin();
	handle_files(argc, argv);
	return (0);
}

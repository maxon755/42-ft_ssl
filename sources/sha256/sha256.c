/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:26:07 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 17:18:26 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

t_sha256_flags g_sha256_flags;

static void		handle_files(int argc, char *const *argv)
{
	int	i;

	i = optind;
	while (i < argc)
		sha256_hash_file(argv[i++]);
}

static int		print_usage(void)
{
	ft_printf("usage: sha256 [-pqrh] [-s string] [files ...]\n"
		"       use -h for help\n");
	return (1);
}

static int		print_help(void)
{
	ft_printf("Secure Hash Algorithm Version 2\n"
		"usage: sha256 [-pqrh] [-s string] [files ...]\n"
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
		g_sha256_flags.p = 1;
		sha256_hash_stdin();
	}
	else if (flag == 'q')
		g_sha256_flags.q = 1;
	else if (flag == 'r')
		g_sha256_flags.r = 1;
	else if (flag == 's')
	{
		g_sha256_flags.s = 1;
		sha256_hash_string(optarg);
	}
}

int				sha256(int argc, char *const *argv)
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
	if (!argv[optind] && !g_sha256_flags.s && !g_sha256_flags.p)
		sha256_hash_stdin();
	handle_files(argc, argv);
	return (0);
}

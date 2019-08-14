/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:26:07 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 17:21:10 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha384.h"

t_sha384_flags g_sha384_flags;

static void		handle_files(int argc, char *const *argv)
{
	int	i;

	i = optind;
	while (i < argc)
		sha384_hash_file(argv[i++]);
}

static int		print_usage(void)
{
	ft_printf("usage: sha384 [-pqrh] [-s string] [files ...]\n"
		"       use -h for help\n");
	return (1);
}

static int		print_help(void)
{
	ft_printf("Secure Hash Algorithm Version 2\n"
		"usage: sha384 [-pqrh] [-s string] [files ...]\n"
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
		g_sha384_flags.p = 1;
		sha384_hash_stdin();
	}
	else if (flag == 'q')
		g_sha384_flags.q = 1;
	else if (flag == 'r')
		g_sha384_flags.r = 1;
	else if (flag == 's')
	{
		g_sha384_flags.s = 1;
		sha384_hash_string(optarg);
	}
}

int				sha384(int argc, char *const *argv)
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
	if (!argv[optind] && !g_sha384_flags.s && !g_sha384_flags.p)
		sha384_hash_stdin();
	handle_files(argc, argv);
	return (0);
}

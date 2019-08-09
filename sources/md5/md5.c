/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/09 20:08:29 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags md5_flags;

void md5_hash_string(char *string)
{
	t_md5_context context;
	unsigned char digest[MD5_DIGEST_SIZE];
	size_t length;

	length = ft_strlen(string);
	md5_init(&context);
	md5_update(&context, (unsigned char *)string, length);
	md5_finish(digest, &context);
	md5_print(digest);
}

void md5_hash_file(char *file_name)
{

}

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
		}
		else if (flag == 'q')
			md5_flags.q = 1;
		else if (flag == 'r')
			md5_flags.r = 1;
		else if (flag == 's')
		{
			md5_flags.s = 1;
			md5_hash_string(optarg);
		}
		else if (flag == '?')
			return (1);
		i++;
	}

	if (!i && !argv[optind])
	{
		ft_putendl("Ready to read from stdin");
	}

	i = optind;
	while (i < argc)
	{
		ft_putendl(argv[i]);
	}

	return 0;
}
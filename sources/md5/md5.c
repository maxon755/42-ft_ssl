/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/09 21:55:40 by maks             ###   ########.fr       */
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
	int 			fd;
	unsigned int 	byte_readed;
	unsigned char 	buffer[MD5_FILE_BUFFER];
	unsigned char	digest[MD5_DIGEST_SIZE];
	struct stat 	path_stat;
	t_md5_context 	context;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return perror("ft_md5");
    stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode)) {
		ft_printf("ft_md5: %s: Is a directory\n", file_name);
		return;
	}
	md5_init(&context);
	while ((byte_readed = read(fd, buffer, MD5_FILE_BUFFER)))
		md5_update(&context, buffer, byte_readed);
	md5_finish(digest, &context);
	close(fd);
	md5_print(digest);
}

void md5_hash_stdin(void)
{
	unsigned int 	byte_readed;
	t_md5_context 	context;
	unsigned char	digest[MD5_DIGEST_SIZE];
	unsigned char 	buffer[MD5_FILE_BUFFER];

	md5_init(&context);
	while ((byte_readed = read(STDIN_FILENO, buffer, MD5_FILE_BUFFER)))
		md5_update(&context, buffer, byte_readed);
	md5_finish(digest, &context);
	md5_print(digest);
}

int				md5(int argc, char * const *argv)
{
	int flag;
	int i;

	ft_printf("argc %i\n", argc);
	if (argc == 1)
		md5_hash_stdin();

	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'p')
		{
			md5_flags.p = 1;
			md5_hash_stdin();
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
	}

	i = optind;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		md5_hash_file(argv[i]);
		i++;
	}

	return 0;
}
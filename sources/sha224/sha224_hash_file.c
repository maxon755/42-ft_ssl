/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_hash_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:40:22 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/13 12:33:04 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

static int	get_file_descriptor(char *file_name)
{
	int				fd;
	struct stat		path_stat;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		perror("ft_sha224");
		return (-1);
	}
	stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("%&ft_sha224: %s: Is a directory\n", 2, file_name);
		return (-1);
	}
	return (fd);
}

void		sha224_hash_file(char *file_name)
{
	int					fd;
	unsigned int		byte_readed;
	unsigned char		buffer[SHA224_FILE_BUFFER];
	unsigned char		digest[SHA224_DIGEST_SIZE];
	t_sha224_context	context;

	if ((fd = get_file_descriptor(file_name)) == -1)
		return ;
	sha224_init(&context);
	while ((byte_readed = read(fd, buffer, SHA224_FILE_BUFFER)) > 0)
		sha224_update(&context, buffer, byte_readed);
	sha224_finish(digest, &context);
	close(fd);
	sha224_print(digest, file_name, FT_TRUE);
}

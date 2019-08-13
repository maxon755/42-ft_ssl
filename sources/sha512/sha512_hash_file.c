/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_hash_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:40:22 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/13 13:20:00 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

static int	get_file_descriptor(char *file_name)
{
	int				fd;
	struct stat		path_stat;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		perror("ft_sha512");
		return (-1);
	}
	stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("%&ft_sha512: %s: Is a directory\n", 2, file_name);
		return (-1);
	}
	return (fd);
}

void		sha512_hash_file(char *file_name)
{
	int					fd;
	unsigned int		byte_readed;
	unsigned char		buffer[SHA512_FILE_BUFFER];
	unsigned char		digest[SHA512_DIGEST_SIZE];
	t_sha512_context	context;

	if ((fd = get_file_descriptor(file_name)) == -1)
		return ;
	sha512_init(&context);
	while ((byte_readed = read(fd, buffer, SHA512_FILE_BUFFER)) > 0)
		sha512_update(&context, buffer, byte_readed);
	sha512_finish(digest, &context);
	close(fd);
	sha512_print(digest, file_name, FT_TRUE);
}

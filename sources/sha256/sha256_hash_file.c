/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:40:22 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/12 13:25:44 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static int	get_file_descriptor(char *file_name)
{
	int				fd;
	struct stat		path_stat;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		perror("ft_sha256");
		return (-1);
	}
	stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("%&ft_sha256: %s: Is a directory\n", 2, file_name);
		return (-1);
	}
	return (fd);
}

void		sha256_hash_file(char *file_name)
{
	int				fd;
	unsigned int	byte_readed;
	unsigned char	buffer[SHA256_FILE_BUFFER];
	unsigned char	digest[SHA256_DIGEST_SIZE];
	t_sha256_context	context;

	if ((fd = get_file_descriptor(file_name)) == -1)
		return ;
	sha256_init(&context);
	while ((byte_readed = read(fd, buffer, SHA256_FILE_BUFFER)) > 0)
		sha256_update(&context, buffer, byte_readed);
	sha256_finish(digest, &context);
	close(fd);
	sha256_print(digest, file_name, FT_TRUE);
}

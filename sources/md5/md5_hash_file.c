/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:40:22 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 17:38:50 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static int	get_file_descriptor(char *file_name)
{
	int				fd;
	struct stat		path_stat;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		perror("ft_md5");
		return (-1);
	}
	stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("%&ft_md5: %s: Is a directory\n", 2, file_name);
		return (-1);
	}
	return (fd);
}

void		md5_hash_file(char *file_name)
{
	int				fd;
	unsigned int	byte_readed;
	unsigned char	buffer[MD5_FILE_BUFFER];
	unsigned char	digest[MD5_DIGEST_SIZE];
	t_md5_context	context;

	if ((fd = get_file_descriptor(file_name)) == -1)
		return ;
	md5_init(&context);
	while ((byte_readed = read(fd, buffer, MD5_FILE_BUFFER)) > 0)
		md5_update(&context, buffer, byte_readed);
	md5_finish(digest, &context);
	close(fd);
	md5_print(digest, file_name, FT_TRUE);
}

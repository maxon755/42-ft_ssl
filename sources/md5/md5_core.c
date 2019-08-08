/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:24:30 by maks              #+#    #+#             */
/*   Updated: 2019/08/08 15:28:24 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"


int		hash_file(char *file_name)
{
	int fd;
	struct stat path_stat;

	fd = open(file_name, O_RDONLY);

	if (fd < 0)
	{
		perror("ft_md5");
	}
	stat(file_name, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		ft_printf("ft_md5: %s: Is a directory\n", file_name);
	}

	hash_stream(fd);
	close(fd);
	return 1;
}

static t_md5_message	*init_chunk_message(uint32_t *chunk, ssize_t chunk_size, size_t file_size)
{
	t_md5_message *message;

	message = (t_md5_message *)malloc(sizeof(t_md5_message));
	ft_bzero(message, sizeof(t_md5_message));
	message->source = (char *)malloc(chunk_size);
	ft_memcpy(message->source, chunk, chunk_size);
	message->source_size = file_size + chunk_size;
	message->chunk_size = chunk_size;
	return (message);
}

static void			prepare_chunk_message(t_md5_message *message)
{
	uint64_t bit_length;

	bit_length = message->source_size * CHAR_BIT;
	message->padding_length = get_padding_size(message->chunk_size) + BYTES_FOR_SIZE;
	message->result_length = message->chunk_size + message->padding_length;
	message->prepared = (unsigned char *)malloc(message->result_length);
	ft_bzero(message->prepared, message->result_length);
	ft_memcpy(message->prepared, message->source, message->chunk_size);
	message->prepared[message->chunk_size] = 0x80;
	ft_memcpy(&message->prepared[message->result_length - BYTES_FOR_SIZE],
				&(bit_length), BYTES_FOR_SIZE);
}

static void handle_file_chunk(t_md5_data *data, size_t file_size, size_t chunk_size)
{
	size_t			i;
	t_md5_message *message;

	message = init_chunk_message(data->x, chunk_size, file_size);
	prepare_chunk_message(message);
	ft_putendl("Prepared string dump:");
	ft_memdump(message->prepared, message->result_length);

	i = 0;
	while (i < message->result_length / MD5_BLOCK_SIZE)
	{
		ft_memcpy(data->x, &(message->prepared[i * MD5_BLOCK_SIZE]), MD5_BLOCK_SIZE);
		compute_hash(data);
		i++;
	}
}

uint32_t		*hash_stream(int fd __unused)
{
	ssize_t			readed;
	size_t			file_size;
	t_md5_data 		*data;

	data = init_data();

	file_size = 0;
	while ((readed = read(fd, data->x, MD5_BLOCK_SIZE)) == MD5_BLOCK_SIZE)
	{
		file_size += readed;
		compute_hash(data);
	}
	handle_file_chunk(data, file_size, readed);

	ft_putendl("Result dump:");
	ft_memdump(data->hash_buffer, MD5_HASH_SIZE);

	return data->hash_buffer;
}

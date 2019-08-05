/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:24:30 by maks              #+#    #+#             */
/*   Updated: 2019/08/03 19:32:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static t_md5_data *init_data(void)
{
	t_md5_data *data;

	data = (t_md5_data *)malloc(sizeof(t_md5_data));
	data->x = (uint32_t *)malloc(sizeof(uint32_t) * 16);
	data->init_buffer = (t_md5_buffer *)malloc(sizeof(t_md5_buffer));
	data->buffer = (t_md5_buffer *)malloc(sizeof(t_md5_buffer));
	ft_bzero(data->x, sizeof(data->x));
	ft_bzero(data->init_buffer, sizeof(t_md5_buffer));
	ft_bzero(data->buffer, sizeof(t_md5_buffer));
	data->init_buffer->a = 0x67452301;
	data->init_buffer->b = 0xEFCDAB89;
	data->init_buffer->c = 0x98BADCFE;
	data->init_buffer->d = 0x10325476;

	return data;
}

static unsigned char *glue_buffer(t_md5_buffer *buffer)
{
	unsigned char *hash;
	size_t hash_size = sizeof(t_md5_buffer) + 1;

	hash = (unsigned char *)malloc(hash_size);
	ft_bzero(hash, hash_size);

	ft_memcpy(hash, buffer, sizeof(t_md5_buffer));
	return hash;
}

unsigned char	*hash_message(unsigned char *message, uint64_t message_length)
{
	size_t			i;
	unsigned char	*hash;
	t_md5_data 		*data;
	uint32_t		tempx[16];
	/* todp: delete it; for testing */
	ft_bzero(tempx, sizeof(uint32_t) * 16);

	data = init_data();

	i = 0;
	while (i < message_length / MD5_BLOCK_SIZE)
	{
		ft_memcpy(data->buffer, data->init_buffer, sizeof(t_md5_buffer));
		ft_memcpy(data->x, &(message[i * MD5_BLOCK_SIZE]), MD5_BLOCK_SIZE);
		ft_memcpy(tempx, &(message[i * MD5_BLOCK_SIZE]), MD5_BLOCK_SIZE);

		compute_hash(data);
		i++;
	}

	hash = glue_buffer(data->init_buffer);

	ft_putendl("Result dump:");
	ft_memdump(hash, ft_strlen((char *)hash));
	ft_putendl("Result hash:");
	ft_putendl((char *)hash);

	return hash;
}
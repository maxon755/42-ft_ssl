/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:24:30 by maks              #+#    #+#             */
/*   Updated: 2019/08/07 16:06:40 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static t_md5_data *init_data(void)
{
	t_md5_data *data;

	data = (t_md5_data *)malloc(sizeof(t_md5_data));
	data->init_buffer = (uint32_t *)malloc(MD5_HASH_SIZE);
	ft_bzero(data->x, sizeof(data->x));
	ft_bzero(data->init_buffer, MD5_HASH_SIZE);
	ft_bzero(data->buffer, MD5_HASH_SIZE);
	data->init_buffer[0] = 0x67452301;
	data->init_buffer[1] = 0xEFCDAB89;
	data->init_buffer[2] = 0x98BADCFE;
	data->init_buffer[3] = 0x10325476;

	return data;
}

t_md5_message	*init_message(char * str)
{
	t_md5_message *message;

	message = (t_md5_message *)malloc(sizeof(t_md5_message));
	ft_bzero(message, sizeof(t_md5_message));
	message->init_str = str;
	message->init_length = ft_strlen(str);
	message->init_length_bit = message->init_length * CHAR_BIT;
	return (message);
}

uint32_t		*hash_string(char * const str)
{
	size_t			i;
	t_md5_message	*message;
	t_md5_data 		*data;

	message = init_message(str);
	prepare_message(message);
	data = init_data();

	i = 0;
	while (i < message->result_length / MD5_BLOCK_SIZE)
	{
		ft_memcpy(data->x, &(message->prepared[i * MD5_BLOCK_SIZE]), MD5_BLOCK_SIZE);
		compute_hash(data);
		i++;
	}

	ft_putendl("Result dump:");
	ft_memdump(data->init_buffer, MD5_HASH_SIZE);

	return data->init_buffer;
}

uint32_t		*hash_message(unsigned char *message, uint64_t message_length)
{
	size_t			i;
	t_md5_data 		*data;

	data = init_data();

	i = 0;
	while (i < message_length / MD5_BLOCK_SIZE)
	{
		ft_memcpy(data->x, &(message[i * MD5_BLOCK_SIZE]), MD5_BLOCK_SIZE);
		compute_hash(data);
		i++;
	}

	ft_putendl("Result dump:");
	ft_memdump(data->init_buffer, MD5_HASH_SIZE);

	return data->init_buffer;
}

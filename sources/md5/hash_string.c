/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:12:09 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/09 17:01:51 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void			prepare_message(t_md5_message *message)
{
	uint64_t bit_length;

	bit_length = message->init_length * CHAR_BIT;
	message->padding_length = get_padding_size(message->init_length) + BYTES_FOR_SIZE;
	message->result_length = message->init_length + message->padding_length;
	message->prepared = (unsigned char *)malloc(message->result_length);
	ft_bzero(message->prepared, message->result_length);
	ft_memcpy(message->prepared, message->source, message->init_length);
	message->prepared[message->init_length] = 0x80;
	ft_memcpy(&message->prepared[message->result_length - BYTES_FOR_SIZE],
				&(bit_length), BYTES_FOR_SIZE);
}

t_md5_message	*init_string_message(char * str)
{
	t_md5_message *message;

	message = (t_md5_message *)malloc(sizeof(t_md5_message));
	ft_bzero(message, sizeof(t_md5_message));
	message->source = str;
	message->init_length = ft_strlen(str);
	return (message);
}

void	hash_string(char *const str)
{
	size_t			i;
	t_md5_message	*message;
	t_md5_data 		*data;

	message = init_string_message(str);
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
	ft_memdump(data->hash_buffer, MD5_HASH_SIZE);
}
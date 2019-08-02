/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:12:09 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/02 15:16:29 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static unsigned int	get_padding_size(unsigned int bit_length)
{
	int delta;

	delta = (448 - bit_length) % 512;
	if (delta <= 0)
		delta += 512;
	return (bit_length + delta) / CHAR_BIT;
}

void				prepare_message(t_md5_message *message)
{
	message->padding_length = get_padding_size(message->init_length_bit);
	message->result_length = message->padding_length + BYTES_FOR_SIZE;
	message->prepared = (unsigned char *)malloc(message->result_length);
	ft_bzero(message->prepared, message->result_length);
	ft_memcpy(message->prepared, message->init_str, message->init_length);
	message->prepared[message->init_length] = 0x80;
	ft_memcpy(&message->prepared[message->result_length - BYTES_FOR_SIZE],
				&(message->init_length_bit), BYTES_FOR_SIZE);
}

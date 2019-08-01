/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:24:30 by maks              #+#    #+#             */
/*   Updated: 2019/08/01 17:04:50 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

unsigned int get_padding_size(unsigned int bit_length)
{
	int delta;
	
	delta = (448 - bit_length) % 512;
	if (delta <= 0) {
		delta += 512;
	}
	return (bit_length + delta);
}


void prepare_message(t_md5_message *message)
{
	message->padding_length_bit = get_padding_size(message->init_length_bit);
}
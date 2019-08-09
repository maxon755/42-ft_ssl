/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:05:34 by maks              #+#    #+#             */
/*   Updated: 2019/08/09 18:28:47 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void md5_init(t_md5_context *context)
{
	context->source_size_bits = 0;
	context->state[0] = 0x67452301;
  	context->state[1] = 0xefcdab89;
  	context->state[2] = 0x98badcfe;
  	context->state[3] = 0x10325476;
}

void md5_update(t_md5_context *context, unsigned char *input, unsigned int input_size)
{
	unsigned int i;
	unsigned int index;
	unsigned int rest_size;

	index = FT_TO_BYTES(context->source_size_bits) % MD5_BLOCK_SIZE;
	context->source_size_bits += FT_TO_BITS(input_size);
	rest_size = MD5_BLOCK_SIZE - index;

	if (input_size > rest_size)
	{
		ft_memcpy(&context->buffer, input, rest_size);
		md5_transform(context->state, context->buffer);
		i = rest_size;
		while(i + MD5_BLOCK_SIZE -1 < input_size)
		{
			md5_transform(context->state, &input[i * MD5_BLOCK_SIZE]);
			i += MD5_BLOCK_SIZE;
		}
		index = 0;
	}
	else
	{
		i = 0;
	}

	ft_memcpy(&context->buffer[index], &input[i], input_size - i);
}

md5_final(unsigned char digest[MD5_HASH_SIZE], t_md5_context *context)
{
	unsigned int index;
	unsigned int padding_size;

	index = FT_TO_BYTES(context->source_size_bits) % MD5_BLOCK_SIZE;
	padding_size = index < 56 ? 56 - index : 120 - index;
	md5_update(context, MD5_PADDING, padding_size);
	md5_update(context, (unsigned char *)&context->source_size_bits, MD5_BYTES_FOR_SIZE);
	ft_bzero(context, sizeof(t_md5_context));
}
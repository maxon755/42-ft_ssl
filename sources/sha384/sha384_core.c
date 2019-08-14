/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:38:58 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 10:57:34 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha384.h"

static unsigned char g_sha384_padding[SHA384_BLOCK_SIZE] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void	sha384_init(t_sha384_context *context)
{
	context->source_size_bits = 0;
	context->state[0] = 0xcbbb9d5dc1059ed8;
	context->state[1] = 0x629a292a367cd507;
	context->state[2] = 0x9159015a3070dd17;
	context->state[3] = 0x152fecd8f70e5939;
	context->state[4] = 0x67332667ffc00b31;
	context->state[5] = 0x8eb44a8768581511;
	context->state[6] = 0xdb0c2e0d64f98fa7;
	context->state[7] = 0x47b5481dbefa4fa4;
}

void	sha384_update(
	t_sha384_context *context,
	unsigned char *input,
	unsigned int input_size)
{
	unsigned int i;
	unsigned int index;
	unsigned int rest_size;

	index = FT_TO_BYTES(context->source_size_bits) % SHA384_BLOCK_SIZE;
	context->source_size_bits += FT_TO_BITS(input_size);
	rest_size = SHA384_BLOCK_SIZE - index;
	if (input_size >= rest_size)
	{
		ft_memcpy(&context->buffer[index], input, rest_size);
		sha384_transform(context->state, context->buffer);
		i = rest_size;
		while (i + SHA384_BLOCK_SIZE - 1 < input_size)
		{
			sha384_transform(context->state, &input[i]);
			i += SHA384_BLOCK_SIZE;
		}
		index = 0;
	}
	else
		i = 0;
	ft_memcpy(&context->buffer[index], &input[i], input_size - i);
}

void	sha384_finish(
	unsigned char digest[SHA384_DIGEST_SIZE],
	t_sha384_context *context)
{
	unsigned int	index;
	unsigned int	padding_size;
	unsigned char	bits[SHA384_BYTES_FOR_SIZE];

	ft_memcpy_rev(bits, &context->source_size_bits, SHA384_BYTES_FOR_SIZE);
	index = FT_TO_BYTES(context->source_size_bits) % SHA384_BLOCK_SIZE;
	padding_size = index < 112 ? 112 - index : 128 - index;
	sha384_update(context, g_sha384_padding, padding_size);
	sha384_update(context, bits, SHA384_BYTES_FOR_SIZE);
	ft_memcpy(digest, context->state, SHA384_DIGEST_SIZE);
	ft_bzero(context, sizeof(t_sha384_context));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:38:58 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 12:37:57 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

static unsigned char g_sha224_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void	sha224_init(t_sha224_context *context)
{
	context->source_size_bits = 0;
	context->state[0] = 0xC1059ED8;
	context->state[1] = 0x367CD507;
	context->state[2] = 0x3070DD17;
	context->state[3] = 0xF70E5939;
	context->state[4] = 0xFFC00B31;
	context->state[5] = 0x68581511;
	context->state[6] = 0x64F98FA7;
	context->state[7] = 0xBEFA4FA4;
}

void	sha224_update(
	t_sha224_context *context,
	unsigned char *input,
	unsigned int input_size)
{
	unsigned int i;
	unsigned int index;
	unsigned int rest_size;

	index = FT_TO_BYTES(context->source_size_bits) % SHA224_BLOCK_SIZE;
	context->source_size_bits += FT_TO_BITS(input_size);
	rest_size = SHA224_BLOCK_SIZE - index;
	if (input_size >= rest_size)
	{
		ft_memcpy(&context->buffer[index], input, rest_size);
		sha224_transform(context->state, context->buffer);
		i = rest_size;
		while (i + SHA224_BLOCK_SIZE - 1 < input_size)
		{
			sha224_transform(context->state, &input[i]);
			i += SHA224_BLOCK_SIZE;
		}
		index = 0;
	}
	else
		i = 0;
	ft_memcpy(&context->buffer[index], &input[i], input_size - i);
}

void	sha224_finish(
	unsigned char digest[SHA224_DIGEST_SIZE],
	t_sha224_context *context)
{
	unsigned int	index;
	unsigned int	padding_size;
	unsigned char	bits[SHA224_BYTES_FOR_SIZE];

	bits[0] = (uint8_t)(context->source_size_bits >> 56);
	bits[1] = (uint8_t)(context->source_size_bits >> 48);
	bits[2] = (uint8_t)(context->source_size_bits >> 40);
	bits[3] = (uint8_t)(context->source_size_bits >> 32);
	bits[4] = (uint8_t)(context->source_size_bits >> 24);
	bits[5] = (uint8_t)(context->source_size_bits >> 16);
	bits[6] = (uint8_t)(context->source_size_bits >> 8);
	bits[7] = (uint8_t)(context->source_size_bits);
	index = FT_TO_BYTES(context->source_size_bits) % SHA224_BLOCK_SIZE;
	padding_size = index < 56 ? 56 - index : 120 - index;
	sha224_update(context, g_sha224_padding, padding_size);
	sha224_update(context, bits, SHA224_BYTES_FOR_SIZE);
	ft_memcpy(digest, context->state, SHA224_DIGEST_SIZE);
	ft_bzero(context, sizeof(t_sha224_context));
}

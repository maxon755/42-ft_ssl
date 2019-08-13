/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:38:58 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 13:20:00 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

static unsigned char g_sha512_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void	sha512_init(t_sha512_context *context)
{
	context->source_size_bits = 0;
	context->state[0] = 0x6A09E667;
	context->state[1] = 0xBB67AE85;
	context->state[2] = 0x3C6EF372;
	context->state[3] = 0xA54FF53A;
	context->state[4] = 0x510E527F;
	context->state[5] = 0x9B05688C;
	context->state[6] = 0x1F83D9AB;
	context->state[7] = 0x5BE0CD19;
}

void	sha512_update(
	t_sha512_context *context,
	unsigned char *input,
	unsigned int input_size)
{
	unsigned int i;
	unsigned int index;
	unsigned int rest_size;

	index = FT_TO_BYTES(context->source_size_bits) % SHA512_BLOCK_SIZE;
	context->source_size_bits += FT_TO_BITS(input_size);
	rest_size = SHA512_BLOCK_SIZE - index;
	if (input_size >= rest_size)
	{
		ft_memcpy(&context->buffer[index], input, rest_size);
		sha512_transform(context->state, context->buffer);
		i = rest_size;
		while (i + SHA512_BLOCK_SIZE - 1 < input_size)
		{
			sha512_transform(context->state, &input[i]);
			i += SHA512_BLOCK_SIZE;
		}
		index = 0;
	}
	else
		i = 0;
	ft_memcpy(&context->buffer[index], &input[i], input_size - i);
}

void	sha512_finish(
	unsigned char digest[SHA512_DIGEST_SIZE],
	t_sha512_context *context)
{
	unsigned int	index;
	unsigned int	padding_size;
	unsigned char	bits[SHA512_BYTES_FOR_SIZE];

	bits[0] = (uint8_t)(context->source_size_bits >> 56);
	bits[1] = (uint8_t)(context->source_size_bits >> 48);
	bits[2] = (uint8_t)(context->source_size_bits >> 40);
	bits[3] = (uint8_t)(context->source_size_bits >> 32);
	bits[4] = (uint8_t)(context->source_size_bits >> 24);
	bits[5] = (uint8_t)(context->source_size_bits >> 16);
	bits[6] = (uint8_t)(context->source_size_bits >> 8);
	bits[7] = (uint8_t)(context->source_size_bits);
	index = FT_TO_BYTES(context->source_size_bits) % SHA512_BLOCK_SIZE;
	padding_size = index < 56 ? 56 - index : 120 - index;
	sha512_update(context, g_sha512_padding, padding_size);
	sha512_update(context, bits, SHA512_BYTES_FOR_SIZE);
	ft_memcpy(digest, context->state, SHA512_DIGEST_SIZE);
	ft_bzero(context, sizeof(t_sha512_context));
}

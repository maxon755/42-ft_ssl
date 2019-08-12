/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:26:10 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/11 13:44:26 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static unsigned char g_sha256_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void	sha256_init(t_sha256_context *context)
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

void	sha256_update(
	t_sha256_context *context,
	unsigned char *input,
	unsigned int input_size)
{
	unsigned int i;
	unsigned int index;
	unsigned int rest_size;

	index = FT_TO_BYTES(context->source_size_bits) % SHA256_BLOCK_SIZE;
	context->source_size_bits += FT_TO_BITS(input_size);
	rest_size = SHA256_BLOCK_SIZE - index;
	if (input_size >= rest_size)
	{
		ft_memcpy(&context->buffer[index], input, rest_size);
		sha256_transform(context->state, context->buffer);
		i = rest_size;
		while (i + SHA256_BLOCK_SIZE - 1 < input_size)
		{
			sha256_transform(context->state, &input[i]);
			i += SHA256_BLOCK_SIZE;
		}
		index = 0;
	}
	else
		i = 0;
	ft_memcpy(&context->buffer[index], &input[i], input_size - i);
}

void	sha256_finish(
	unsigned char digest[SHA256_DIGEST_SIZE],
	t_sha256_context *context)
{
	unsigned int	index;
	unsigned int	padding_size;
	unsigned char	bits[SHA256_BYTES_FOR_SIZE];

	bits[0] = (uint8_t)(context->source_size_bits >> 56);
	bits[1] = (uint8_t)(context->source_size_bits >> 48);
	bits[2] = (uint8_t)(context->source_size_bits >> 40);
	bits[3] = (uint8_t)(context->source_size_bits >> 32);
	bits[4] = (uint8_t)(context->source_size_bits >> 24);
	bits[5] = (uint8_t)(context->source_size_bits >> 16);
	bits[6] = (uint8_t)(context->source_size_bits >> 8);
	bits[7] = (uint8_t)(context->source_size_bits);

	index = FT_TO_BYTES(context->source_size_bits) % SHA256_BLOCK_SIZE;
	padding_size = index < 56 ? 56 - index : 120 - index;
	sha256_update(context, g_sha256_padding, padding_size);
	sha256_update(context, bits, SHA256_BYTES_FOR_SIZE);
	ft_memcpy(digest, context->state, SHA256_DIGEST_SIZE);
	ft_bzero(context, sizeof(t_sha256_context));
}
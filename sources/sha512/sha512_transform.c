/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:50:23 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 13:22:13 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

static const uint32_t g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
	0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
	0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
	0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
	0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void	init_buffer(
			uint32_t w[SHA512_BUFFER_SIZE],
			unsigned char block[SHA512_BLOCK_SIZE])
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		w[i] = (((uint32_t)block[i * 4]) << 24) |
			(((uint32_t)block[i * 4 + 1]) << 16) |
			(((uint32_t)block[i * 4 + 2]) << 8) |
			(((uint32_t)block[i * 4 + 3]));
		i++;
	}
	while (i < SHA512_BLOCK_SIZE)
	{
		w[i] = SHA512_SIGMA4(w[i - 2]) + w[i - 7] +
				SHA512_SIGMA3(w[i - 15]) + w[i - 16];
		i++;
	}
}

static void	update_state(
	uint32_t state[SHA512_STATE_SIZE],
	uint32_t temp_state[SHA512_STATE_SIZE])
{
	state[0] += SHA512_A;
	state[1] += SHA512_B;
	state[2] += SHA512_C;
	state[3] += SHA512_D;
	state[4] += SHA512_E;
	state[5] += SHA512_F;
	state[6] += SHA512_G;
	state[7] += SHA512_H;
}

void		sha512_transform(
	uint64_t state[SHA512_STATE_SIZE],
	unsigned char block[SHA512_BLOCK_SIZE])
{
	unsigned int	i;
	uint64_t		temp_state[SHA512_STATE_SIZE];
	uint64_t		w[64];
	uint64_t		temp1;
	uint64_t		temp2;

	ft_memcpy(temp_state, state, SHA512_DIGEST_SIZE);
	init_buffer(w, block);
	i = -1;
	while (++i < SHA512_BLOCK_SIZE)
	{
		temp1 = SHA512_H + SHA512_SIGMA2(SHA512_E) +
				SHA512_CH(SHA512_E, SHA512_F, SHA512_G) + g_k[i] + w[i];
		temp2 = SHA512_SIGMA1(SHA512_A) +
				SHA512_MAJ(SHA512_A, SHA512_B, SHA512_C);
		SHA512_H = SHA512_G;
		SHA512_G = SHA512_F;
		SHA512_F = SHA512_E;
		SHA512_E = SHA512_D + temp1;
		SHA512_D = SHA512_C;
		SHA512_C = SHA512_B;
		SHA512_B = SHA512_A;
		SHA512_A = temp1 + temp2;
	}
	update_state(state, temp_state);
}

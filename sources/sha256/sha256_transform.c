/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:50:23 by maks              #+#    #+#             */
/*   Updated: 2019/08/12 13:41:55 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

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
			uint32_t w[SHA256_BUFFER_SIZE],
			unsigned char block[SHA256_BLOCK_SIZE])
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
	while (i < SHA256_BLOCK_SIZE)
	{
		w[i] = SHA256_SIGMA4(w[i - 2]) + w[i - 7] +
				SHA256_SIGMA3(w[i - 15]) + w[i - 16];
		i++;
	}
}

static void	update_state(
	uint32_t state[SHA256_STATE_SIZE],
	uint32_t temp_state[SHA256_STATE_SIZE])
{
	state[0] += SHA256_A;
	state[1] += SHA256_B;
	state[2] += SHA256_C;
	state[3] += SHA256_D;
	state[4] += SHA256_E;
	state[5] += SHA256_F;
	state[6] += SHA256_G;
	state[7] += SHA256_H;
}

void		sha256_transform(
	uint32_t state[SHA256_STATE_SIZE],
	unsigned char block[SHA256_BLOCK_SIZE])
{
	unsigned int	i;
	uint32_t		temp_state[SHA256_STATE_SIZE];
	uint32_t		w[64];
	uint32_t		temp1;
	uint32_t		temp2;

	ft_memcpy(temp_state, state, SHA256_DIGEST_SIZE);
	init_buffer(w, block);
	i = 0;
	while (i < SHA256_BLOCK_SIZE)
	{
		temp1 = SHA256_H + SHA256_SIGMA2(SHA256_E) +
				SHA256_CH(SHA256_E, SHA256_F, SHA256_G) + g_k[i] + w[i++];
		temp2 = SHA256_SIGMA1(SHA256_A) +
				SHA256_MAJ(SHA256_A, SHA256_B, SHA256_C);
		SHA256_H = SHA256_G;
		SHA256_G = SHA256_F;
		SHA256_F = SHA256_E;
		SHA256_E = SHA256_D + temp1;
		SHA256_D = SHA256_C;
		SHA256_C = SHA256_B;
		SHA256_B = SHA256_A;
		SHA256_A = temp1 + temp2;
	}
	update_state(state, temp_state);
}

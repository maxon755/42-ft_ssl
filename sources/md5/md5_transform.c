/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:43:03 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/09 18:08:15 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void round1(uint32_t s[4], uint32_t x[16])
{
    FF(s[0], s[1], s[2], s[3], x[0], S11, 0xd76aa478);
    FF(s[3], s[0], s[1], s[2], x[1], S12, 0xe8c7b756);
    FF(s[2], s[3], s[0], s[1], x[2], S13, 0x242070db);
    FF(s[1], s[2], s[3], s[0], x[3], S14, 0xc1bdceee);
    FF(s[0], s[1], s[2], s[3], x[4], S11, 0xf57c0faf);
    FF(s[3], s[0], s[1], s[2], x[5], S12, 0x4787c62a);
    FF(s[2], s[3], s[0], s[1], x[6], S13, 0xa8304613);
    FF(s[1], s[2], s[3], s[0], x[7], S14, 0xfd469501);
    FF(s[0], s[1], s[2], s[3], x[8], S11, 0x698098d8);
    FF(s[3], s[0], s[1], s[2], x[9], S12, 0x8b44f7af);
    FF(s[2], s[3], s[0], s[1], x[10], S13, 0xffff5bb1);
    FF(s[1], s[2], s[3], s[0], x[11], S14, 0x895cd7be);
    FF(s[0], s[1], s[2], s[3], x[12], S11, 0x6b901122);
    FF(s[3], s[0], s[1], s[2], x[13], S12, 0xfd987193);
    FF(s[2], s[3], s[0], s[1], x[14], S13, 0xa679438e);
    FF(s[1], s[2], s[3], s[0], x[15], S14, 0x49b40821);
}

static void round2(uint32_t s[4], uint32_t x[16])
{
    GG(s[0], s[1], s[2], s[3], x[1], S21, 0xf61e2562);
    GG(s[3], s[0], s[1], s[2], x[6], S22, 0xc040b340);
    GG(s[2], s[3], s[0], s[1], x[11], S23, 0x265e5a51);
    GG(s[1], s[2], s[3], s[0], x[0], S24, 0xe9b6c7aa);
    GG(s[0], s[1], s[2], s[3], x[5], S21, 0xd62f105d);
    GG(s[3], s[0], s[1], s[2], x[10], S22,  0x2441453);
    GG(s[2], s[3], s[0], s[1], x[15], S23, 0xd8a1e681);
    GG(s[1], s[2], s[3], s[0], x[4], S24, 0xe7d3fbc8);
    GG(s[0], s[1], s[2], s[3], x[9], S21, 0x21e1cde6);
    GG(s[3], s[0], s[1], s[2], x[14], S22, 0xc33707d6);
    GG(s[2], s[3], s[0], s[1], x[3], S23, 0xf4d50d87);
    GG(s[1], s[2], s[3], s[0], x[8], S24, 0x455a14ed);
    GG(s[0], s[1], s[2], s[3], x[13], S21, 0xa9e3e905);
    GG(s[3], s[0], s[1], s[2], x[2], S22, 0xfcefa3f8);
    GG(s[2], s[3], s[0], s[1], x[7], S23, 0x676f02d9);
    GG(s[1], s[2], s[3], s[0], x[12], S24, 0x8d2a4c8a);
}

static void round3(uint32_t s[4], uint32_t x[16])
{
    HH(s[0], s[1], s[2], s[3], x[5], S31, 0xfffa3942);
    HH(s[3], s[0], s[1], s[2], x[8], S32, 0x8771f681);
    HH(s[2], s[3], s[0], s[1], x[11], S33, 0x6d9d6122);
    HH(s[1], s[2], s[3], s[0], x[14], S34, 0xfde5380c);
    HH(s[0], s[1], s[2], s[3], x[1], S31, 0xa4beea44);
    HH(s[3], s[0], s[1], s[2], x[4], S32, 0x4bdecfa9);
    HH(s[2], s[3], s[0], s[1], x[7], S33, 0xf6bb4b60);
    HH(s[1], s[2], s[3], s[0], x[10], S34, 0xbebfbc70);
    HH(s[0], s[1], s[2], s[3], x[13], S31, 0x289b7ec6);
    HH(s[3], s[0], s[1], s[2], x[0], S32, 0xeaa127fa);
    HH(s[2], s[3], s[0], s[1], x[3], S33, 0xd4ef3085);
    HH(s[1], s[2], s[3], s[0], x[6], S34,  0x4881d05);
    HH(s[0], s[1], s[2], s[3], x[9], S31, 0xd9d4d039);
    HH(s[3], s[0], s[1], s[2], x[12], S32, 0xe6db99e5);
    HH(s[2], s[3], s[0], s[1], x[15], S33, 0x1fa27cf8);
    HH(s[1], s[2], s[3], s[0], x[2], S34, 0xc4ac5665);
}

static void round4(uint32_t s[4], uint32_t x[16])
{
    II(s[0], s[1], s[2], s[3], x[0], S41, 0xf4292244);
    II(s[3], s[0], s[1], s[2], x[7], S42, 0x432aff97);
    II(s[2], s[3], s[0], s[1], x[14], S43, 0xab9423a7);
    II(s[1], s[2], s[3], s[0], x[5], S44, 0xfc93a039);
    II(s[0], s[1], s[2], s[3], x[12], S41, 0x655b59c3);
    II(s[3], s[0], s[1], s[2], x[3], S42, 0x8f0ccc92);
    II(s[2], s[3], s[0], s[1], x[10], S43, 0xffeff47d);
    II(s[1], s[2], s[3], s[0], x[1], S44, 0x85845dd1);
    II(s[0], s[1], s[2], s[3], x[8], S41, 0x6fa87e4f);
    II(s[3], s[0], s[1], s[2], x[15], S42, 0xfe2ce6e0);
    II(s[2], s[3], s[0], s[1], x[6], S43, 0xa3014314);
    II(s[1], s[2], s[3], s[0], x[13], S44, 0x4e0811a1);
    II(s[0], s[1], s[2], s[3], x[4], S41, 0xf7537e82);
    II(s[3], s[0], s[1], s[2], x[11], S42, 0xbd3af235);
    II(s[2], s[3], s[0], s[1], x[2], S43, 0x2ad7d2bb);
    II(s[1], s[2], s[3], s[0], x[9], S44, 0xeb86d391);
}

void md5_transform(uint32_t state[4], unsigned char *block)
{
	uint32_t temp_state[4];
	uint32_t x[16];

	ft_memcpy(temp_state, state, MD5_HASH_SIZE);
	ft_memcpy(x, block, MD5_BLOCK_SIZE);
    round1(temp_state, x);
    round2(temp_state, x);
    round3(temp_state, x);
    round4(temp_state, x);
    state[0] += temp_state[0];
    state[1] += temp_state[1];
    state[2] += temp_state[2];
    state[3] += temp_state[3];
}
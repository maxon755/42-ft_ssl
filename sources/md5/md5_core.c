/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:43:03 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/08 17:32:25 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void round1(uint32_t *b, uint32_t *x)
{
    FF(b[0], b[1], b[2], b[3], x[0], S11, 0xd76aa478);
    FF(b[3], b[0], b[1], b[2], x[1], S12, 0xe8c7b756);
    FF(b[2], b[3], b[0], b[1], x[2], S13, 0x242070db);
    FF(b[1], b[2], b[3], b[0], x[3], S14, 0xc1bdceee);
    FF(b[0], b[1], b[2], b[3], x[4], S11, 0xf57c0faf);
    FF(b[3], b[0], b[1], b[2], x[5], S12, 0x4787c62a);
    FF(b[2], b[3], b[0], b[1], x[6], S13, 0xa8304613);
    FF(b[1], b[2], b[3], b[0], x[7], S14, 0xfd469501);
    FF(b[0], b[1], b[2], b[3], x[8], S11, 0x698098d8);
    FF(b[3], b[0], b[1], b[2], x[9], S12, 0x8b44f7af);
    FF(b[2], b[3], b[0], b[1], x[10], S13, 0xffff5bb1);
    FF(b[1], b[2], b[3], b[0], x[11], S14, 0x895cd7be);
    FF(b[0], b[1], b[2], b[3], x[12], S11, 0x6b901122);
    FF(b[3], b[0], b[1], b[2], x[13], S12, 0xfd987193);
    FF(b[2], b[3], b[0], b[1], x[14], S13, 0xa679438e);
    FF(b[1], b[2], b[3], b[0], x[15], S14, 0x49b40821);
}

static void round2(uint32_t *b, uint32_t *x)
{
    GG(b[0], b[1], b[2], b[3], x[1], S21, 0xf61e2562);
    GG(b[3], b[0], b[1], b[2], x[6], S22, 0xc040b340);
    GG(b[2], b[3], b[0], b[1], x[11], S23, 0x265e5a51);
    GG(b[1], b[2], b[3], b[0], x[0], S24, 0xe9b6c7aa);
    GG(b[0], b[1], b[2], b[3], x[5], S21, 0xd62f105d);
    GG(b[3], b[0], b[1], b[2], x[10], S22,  0x2441453);
    GG(b[2], b[3], b[0], b[1], x[15], S23, 0xd8a1e681);
    GG(b[1], b[2], b[3], b[0], x[4], S24, 0xe7d3fbc8);
    GG(b[0], b[1], b[2], b[3], x[9], S21, 0x21e1cde6);
    GG(b[3], b[0], b[1], b[2], x[14], S22, 0xc33707d6);
    GG(b[2], b[3], b[0], b[1], x[3], S23, 0xf4d50d87);
    GG(b[1], b[2], b[3], b[0], x[8], S24, 0x455a14ed);
    GG(b[0], b[1], b[2], b[3], x[13], S21, 0xa9e3e905);
    GG(b[3], b[0], b[1], b[2], x[2], S22, 0xfcefa3f8);
    GG(b[2], b[3], b[0], b[1], x[7], S23, 0x676f02d9);
    GG(b[1], b[2], b[3], b[0], x[12], S24, 0x8d2a4c8a);
}

static void round3(uint32_t *b, uint32_t *x)
{
    HH(b[0], b[1], b[2], b[3], x[5], S31, 0xfffa3942);
    HH(b[3], b[0], b[1], b[2], x[8], S32, 0x8771f681);
    HH(b[2], b[3], b[0], b[1], x[11], S33, 0x6d9d6122);
    HH(b[1], b[2], b[3], b[0], x[14], S34, 0xfde5380c);
    HH(b[0], b[1], b[2], b[3], x[1], S31, 0xa4beea44);
    HH(b[3], b[0], b[1], b[2], x[4], S32, 0x4bdecfa9);
    HH(b[2], b[3], b[0], b[1], x[7], S33, 0xf6bb4b60);
    HH(b[1], b[2], b[3], b[0], x[10], S34, 0xbebfbc70);
    HH(b[0], b[1], b[2], b[3], x[13], S31, 0x289b7ec6);
    HH(b[3], b[0], b[1], b[2], x[0], S32, 0xeaa127fa);
    HH(b[2], b[3], b[0], b[1], x[3], S33, 0xd4ef3085);
    HH(b[1], b[2], b[3], b[0], x[6], S34,  0x4881d05);
    HH(b[0], b[1], b[2], b[3], x[9], S31, 0xd9d4d039);
    HH(b[3], b[0], b[1], b[2], x[12], S32, 0xe6db99e5);
    HH(b[2], b[3], b[0], b[1], x[15], S33, 0x1fa27cf8);
    HH(b[1], b[2], b[3], b[0], x[2], S34, 0xc4ac5665);
}

static void round4(uint32_t *b, uint32_t *x)
{
    II(b[0], b[1], b[2], b[3], x[0], S41, 0xf4292244);
    II(b[3], b[0], b[1], b[2], x[7], S42, 0x432aff97);
    II(b[2], b[3], b[0], b[1], x[14], S43, 0xab9423a7);
    II(b[1], b[2], b[3], b[0], x[5], S44, 0xfc93a039);
    II(b[0], b[1], b[2], b[3], x[12], S41, 0x655b59c3);
    II(b[3], b[0], b[1], b[2], x[3], S42, 0x8f0ccc92);
    II(b[2], b[3], b[0], b[1], x[10], S43, 0xffeff47d);
    II(b[1], b[2], b[3], b[0], x[1], S44, 0x85845dd1);
    II(b[0], b[1], b[2], b[3], x[8], S41, 0x6fa87e4f);
    II(b[3], b[0], b[1], b[2], x[15], S42, 0xfe2ce6e0);
    II(b[2], b[3], b[0], b[1], x[6], S43, 0xa3014314);
    II(b[1], b[2], b[3], b[0], x[13], S44, 0x4e0811a1);
    II(b[0], b[1], b[2], b[3], x[4], S41, 0xf7537e82);
    II(b[3], b[0], b[1], b[2], x[11], S42, 0xbd3af235);
    II(b[2], b[3], b[0], b[1], x[2], S43, 0x2ad7d2bb);
    II(b[1], b[2], b[3], b[0], x[9], S44, 0xeb86d391);
}

void compute_hash(t_md5_data *data)
{
	ft_memcpy(data->buffer, data->hash_buffer, MD5_HASH_SIZE);
    round1(data->buffer, data->x);
    round2(data->buffer, data->x);
    round3(data->buffer, data->x);
    round4(data->buffer, data->x);
    data->hash_buffer[0] += data->buffer[0];
    data->hash_buffer[1] += data->buffer[1];
    data->hash_buffer[2] += data->buffer[2];
    data->hash_buffer[3] += data->buffer[3];
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:43:03 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/03 18:46:25 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void round1(t_md5_buffer *b, uint32_t *x)
{
    FF(b->a, b->b, b->c, b->d, x[0], S11, 0xd76aa478);
    FF(b->d, b->a, b->b, b->c, x[1], S12, 0xe8c7b756);
    FF(b->c, b->d, b->a, b->b, x[2], S13, 0x242070db);
    FF(b->b, b->c, b->d, b->a, x[3], S14, 0xc1bdceee);
    FF(b->a, b->b, b->c, b->d, x[4], S11, 0xf57c0faf);
    FF(b->d, b->a, b->b, b->c, x[5], S12, 0x4787c62a);
    FF(b->c, b->d, b->a, b->b, x[6], S13, 0xa8304613);
    FF(b->b, b->c, b->d, b->a, x[7], S14, 0xfd469501);
    FF(b->a, b->b, b->c, b->d, x[8], S11, 0x698098d8);
    FF(b->d, b->a, b->b, b->c, x[9], S12, 0x8b44f7af);
    FF(b->c, b->d, b->a, b->b, x[10], S13, 0xffff5bb1);
    FF(b->b, b->c, b->d, b->a, x[11], S14, 0x895cd7be);
    FF(b->a, b->b, b->c, b->d, x[12], S11, 0x6b901122);
    FF(b->d, b->a, b->b, b->c, x[13], S12, 0xfd987193);
    FF(b->c, b->d, b->a, b->b, x[14], S13, 0xa679438e);
    FF(b->b, b->c, b->d, b->a, x[15], S14, 0x49b40821);
}

static void round2(t_md5_buffer *b, uint32_t *x)
{
    GG(b->a, b->b, b->c, b->d, x[1], S21, 0xf61e2562);
    GG(b->d, b->a, b->b, b->c, x[6], S22, 0xc040b340);
    GG(b->c, b->d, b->a, b->b, x[11], S23, 0x265e5a51);
    GG(b->b, b->c, b->d, b->a, x[0], S24, 0xe9b6c7aa);
    GG(b->a, b->b, b->c, b->d, x[5], S21, 0xd62f105d);
    GG(b->d, b->a, b->b, b->c, x[10], S22,  0x2441453);
    GG(b->c, b->d, b->a, b->b, x[15], S23, 0xd8a1e681);
    GG(b->b, b->c, b->d, b->a, x[4], S24, 0xe7d3fbc8);
    GG(b->a, b->b, b->c, b->d, x[9], S21, 0x21e1cde6);
    GG(b->d, b->a, b->b, b->c, x[14], S22, 0xc33707d6);
    GG(b->c, b->d, b->a, b->b, x[3], S23, 0xf4d50d87);
    GG(b->b, b->c, b->d, b->a, x[8], S24, 0x455a14ed);
    GG(b->a, b->b, b->c, b->d, x[13], S21, 0xa9e3e905);
    GG(b->d, b->a, b->b, b->c, x[2], S22, 0xfcefa3f8);
    GG(b->c, b->d, b->a, b->b, x[7], S23, 0x676f02d9);
    GG(b->b, b->c, b->d, b->a, x[12], S24, 0x8d2a4c8a);
}

static void round3(t_md5_buffer *b, uint32_t *x)
{
    HH(b->a, b->b, b->c, b->d, x[5], S31, 0xfffa3942);
    HH(b->d, b->a, b->b, b->c, x[8], S32, 0x8771f681);
    HH(b->c, b->d, b->a, b->b, x[11], S33, 0x6d9d6122);
    HH(b->b, b->c, b->d, b->a, x[14], S34, 0xfde5380c);
    HH(b->a, b->b, b->c, b->d, x[1], S31, 0xa4beea44);
    HH(b->d, b->a, b->b, b->c, x[4], S32, 0x4bdecfa9);
    HH(b->c, b->d, b->a, b->b, x[7], S33, 0xf6bb4b60);
    HH(b->b, b->c, b->d, b->a, x[10], S34, 0xbebfbc70);
    HH(b->a, b->b, b->c, b->d, x[13], S31, 0x289b7ec6);
    HH(b->d, b->a, b->b, b->c, x[0], S32, 0xeaa127fa);
    HH(b->c, b->d, b->a, b->b, x[3], S33, 0xd4ef3085);
    HH(b->b, b->c, b->d, b->a, x[6], S34,  0x4881d05);
    HH(b->a, b->b, b->c, b->d, x[9], S31, 0xd9d4d039);
    HH(b->d, b->a, b->b, b->c, x[12], S32, 0xe6db99e5);
    HH(b->c, b->d, b->a, b->b, x[15], S33, 0x1fa27cf8);
    HH(b->b, b->c, b->d, b->a, x[2], S34, 0xc4ac5665);
}

static void round4(t_md5_buffer *b, uint32_t *x)
{
    II(b->a, b->b, b->c, b->d, x[0], S41, 0xf4292244);
    II(b->d, b->a, b->b, b->c, x[7], S42, 0x432aff97);
    II(b->c, b->d, b->a, b->b, x[14], S43, 0xab9423a7);
    II(b->b, b->c, b->d, b->a, x[5], S44, 0xfc93a039);
    II(b->a, b->b, b->c, b->d, x[12], S41, 0x655b59c3);
    II(b->d, b->a, b->b, b->c, x[3], S42, 0x8f0ccc92);
    II(b->c, b->d, b->a, b->b, x[10], S43, 0xffeff47d);
    II(b->b, b->c, b->d, b->a, x[1], S44, 0x85845dd1);
    II(b->a, b->b, b->c, b->d, x[8], S41, 0x6fa87e4f);
    II(b->d, b->a, b->b, b->c, x[15], S42, 0xfe2ce6e0);
    II(b->c, b->d, b->a, b->b, x[6], S43, 0xa3014314);
    II(b->b, b->c, b->d, b->a, x[13], S44, 0x4e0811a1);
    II(b->a, b->b, b->c, b->d, x[4], S41, 0xf7537e82);
    II(b->d, b->a, b->b, b->c, x[11], S42, 0xbd3af235);
    II(b->c, b->d, b->a, b->b, x[2], S43, 0x2ad7d2bb);
    II(b->b, b->c, b->d, b->a, x[9], S44, 0xeb86d391);
}

void compute_hash(t_md5_data *data)
{
    round1(data->buffer, data->x);
    round2(data->buffer, data->x);
    round3(data->buffer, data->x);
    round4(data->buffer, data->x);
    data->init_buffer->a += data->buffer->a;
    data->init_buffer->b += data->buffer->b;
    data->init_buffer->c += data->buffer->c;
    data->init_buffer->d += data->buffer->d;
}
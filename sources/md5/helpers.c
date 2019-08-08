/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:55:18 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/08 14:45:11 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"


t_md5_data *init_data(void)
{
	t_md5_data *data;

	data = (t_md5_data *)malloc(sizeof(t_md5_data));
	data->hash_buffer = (uint32_t *)malloc(MD5_HASH_SIZE);
	ft_bzero(data->x, sizeof(data->x));
	ft_bzero(data->hash_buffer, MD5_HASH_SIZE);
	ft_bzero(data->buffer, MD5_HASH_SIZE);
	data->hash_buffer[0] = 0x67452301;
	data->hash_buffer[1] = 0xEFCDAB89;
	data->hash_buffer[2] = 0x98BADCFE;
	data->hash_buffer[3] = 0x10325476;

	return data;
}
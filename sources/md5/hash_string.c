/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:41:32 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 13:08:21 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	md5_hash_string(char *string)
{
	t_md5_context	context;
	unsigned char	digest[MD5_DIGEST_SIZE];
	size_t			length;

	length = ft_strlen(string);
	md5_init(&context);
	md5_update(&context, (unsigned char *)string, length);
	md5_finish(digest, &context);
	md5_print(digest, string, FT_FALSE);
}
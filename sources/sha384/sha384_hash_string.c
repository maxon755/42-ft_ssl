/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_hash_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:40:00 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 10:55:39 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha384.h"

void	sha384_hash_string(char *string)
{
	t_sha384_context	context;
	unsigned char		digest[SHA384_DIGEST_SIZE];
	size_t				length;

	length = ft_strlen(string);
	sha384_init(&context);
	sha384_update(&context, (unsigned char *)string, length);
	sha384_finish(digest, &context);
	sha384_print(digest, string, FT_FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_hash_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:40:00 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 12:33:07 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

void	sha224_hash_string(char *string)
{
	t_sha224_context	context;
	unsigned char		digest[SHA224_DIGEST_SIZE];
	size_t				length;

	length = ft_strlen(string);
	sha224_init(&context);
	sha224_update(&context, (unsigned char *)string, length);
	sha224_finish(digest, &context);
	sha224_print(digest, string, FT_FALSE);
}

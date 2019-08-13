/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_hash_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:40:00 by maks              #+#    #+#             */
/*   Updated: 2019/08/13 13:20:00 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

void	sha512_hash_string(char *string)
{
	t_sha512_context	context;
	unsigned char		digest[SHA512_DIGEST_SIZE];
	size_t				length;

	length = ft_strlen(string);
	sha512_init(&context);
	sha512_update(&context, (unsigned char *)string, length);
	sha512_finish(digest, &context);
	sha512_print(digest, string, FT_FALSE);
}

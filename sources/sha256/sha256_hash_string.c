/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:40:00 by maks              #+#    #+#             */
/*   Updated: 2019/08/12 13:42:52 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void	sha256_hash_string(char *string)
{
	t_sha256_context	context;
	unsigned char		digest[SHA256_DIGEST_SIZE];
	size_t				length;

	length = ft_strlen(string);
	sha256_init(&context);
	sha256_update(&context, (unsigned char *)string, length);
	sha256_finish(digest, &context);
	sha256_print(digest, string, FT_FALSE);
}

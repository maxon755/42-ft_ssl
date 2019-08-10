/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_256_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:26:10 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 17:29:38 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha_256.h"

void	md5_init(t_sha_256_context *context)
{
	context->source_size_bits = 0;
	context->state[0] = 0x6A09E667;
	context->state[1] = 0xBB67AE85;
	context->state[2] = 0x3C6EF372;
	context->state[3] = 0xA54FF53A;
	context->state[4] = 0x510E527F;
	context->state[5] = 0x9B05688C;
	context->state[6] = 0x1F83D9AB;
	context->state[7] = 0x5BE0CD19;
}
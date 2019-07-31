/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/07/31 18:06:57 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags md5_flags;

t_md5_message *initilize_message(char * str)
{
	t_md5_message *message;

	message = (t_md5_message *)malloc(sizeof(message));
	ft_bzero(message, sizeof(message));

	message->init_str = str;
	message->init_length = ft_strlen(str);
	message->init_length_bit = message->init_length * CHAR_BIT;

	return (message);
}

int md5(int argc, char * const *argv)
{
	t_md5_message *message;

	parse_flags(argc, argv);

	if (md5_flags.wrong_argument) {
		return (1);
	}

	ft_printf("arguments end at: %u\n", optind);
	ft_put_strarr(&argv[optind]);

	message = initilize_message(argv[optind]);
	prepare_message(message);

	return 0;
}
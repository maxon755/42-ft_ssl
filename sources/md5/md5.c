/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:04 by maks              #+#    #+#             */
/*   Updated: 2019/08/07 19:47:00 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

t_md5_flags md5_flags;

int				md5(int argc, char * const *argv)
{
	int i;

	parse_flags(argc, argv);

	if (md5_flags.wrong_argument) {
		return (1);
	}

	if (md5_flags.s)
	{
		hash_string(md5_flags.s_arg);
	}

	i = optind;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		hash_file(argv[i++]);
	}

	// ft_putendl("Prepared string dump:");
	// ft_memdump(message->prepared, message->result_length);
	// hash_message(message->prepared, message->result_length);

	return 0;
}
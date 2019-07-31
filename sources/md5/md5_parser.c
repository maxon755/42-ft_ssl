/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:49:48 by maks              #+#    #+#             */
/*   Updated: 2019/07/31 18:13:11 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void parse_flags(int argc, char * const *argv)
{
	int flag;

	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'p')
			md5_flags.p = 1;
		else if (flag == 'q')
			md5_flags.q = 1;
		else if (flag == 'r')
			md5_flags.r = 1;
		else if (flag == 's') {
			md5_flags.s = 1;
			md5_flags.s_arg = optarg;
		} else if (flag == '?') {
			md5_flags.wrong_argument = 1;
		}
	}
}
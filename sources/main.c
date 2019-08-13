/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:47:15 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/13 12:34:22 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ssl.h"

const t_hash_algo g_algo_list[ALGO_QTY] =
{
	{"md5", DIGEST, md5},
	{"sha256", DIGEST, sha256},
	{"sha224", DIGEST, sha224},
};

t_hash_func	dispatch(char *algo_name)
{
	unsigned int i;

	i = 0;
	while (i < ALGO_QTY)
	{
		if (ft_strcmp(algo_name, g_algo_list[i].name) == 0)
			return (g_algo_list[i].func);
		i++;
	}
	return (NULL);
}

int			main(int argc, char *const *argv)
{
	t_hash_func func;

	func = dispatch(argv[1]);
	if (!func)
	{
		print_error_message(argv[1]);
		ft_putchar('\n');
		print_help_message();
		return (1);
	}
	return (func(argc - 1, &(argv[1])));
}

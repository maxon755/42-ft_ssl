/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:41:22 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/10 14:55:07 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_error_message(char *wrong_name)
{
	ft_printf("ft_ssl: Error: %s is an invalid command.\n", wrong_name);
}

void		print_help_message(void)
{
	unsigned int i;

	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	i = 0;
	while (i < ALGO_QTY)
	{
		if (g_algo_list[i].category == DIGEST)
			ft_putendl(g_algo_list[i].name);
		i++;
	}
}
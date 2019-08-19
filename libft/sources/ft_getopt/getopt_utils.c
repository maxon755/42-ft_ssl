/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:02:58 by maks              #+#    #+#             */
/*   Updated: 2019/07/23 15:50:28 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

int		is_flag(char *const str)
{
	return (str != NULL && str[0] == '-' && str[1] != '\0');
}

void	print_flag(t_flag *flag)
{
	ft_printf("Flag info:\n");
	ft_printf("\tsymbol: %c\n", flag->symbol);
	ft_printf("\tvalid: %i\n", flag->valid);
	ft_printf("\tis last symbol: %i\n", flag->is_last_symbol);
	ft_printf("\tstring: %s\n", flag->str);
	ft_printf("\tis multi symbol: %i\n", flag->is_multi_symbol);
	ft_printf("\thas arguments: %i\n", flag->has_arg);
}

void	set_global_vars(int optind_inc, int g_flag_pos)
{
	optind += optind_inc;
	g_flag_position = g_flag_pos;
}

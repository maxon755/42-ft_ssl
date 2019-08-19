/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_c_wide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:17:36 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/07 14:48:15 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	count_active_bits(intmax_t n)
{
	short k;

	n = FT_ABS(n);
	k = 0;
	while (n >> k)
		k++;
	return (k);
}

static char		*utf8_encode(int val, short nb)
{
	char *arr;

	arr = NULL;
	if (nb <= 11 && MB_CUR_MAX >= 2)
	{
		arr = ft_strnew(2);
		arr[0] = 0b11000000 | (val >> 6);
		arr[1] = (0b10000000 | val) & 0b10111111;
	}
	else if (nb <= 16 && MB_CUR_MAX >= 3)
	{
		arr = ft_strnew(3);
		arr[0] = 0b11100000 | (val >> 12);
		arr[1] = (0b10000000 | (val >> 6)) & 0b10111111;
		arr[2] = (0b10000000 | val) & 0b10111111;
	}
	else if (nb <= 21 && MB_CUR_MAX >= 4)
	{
		arr = ft_strnew(4);
		arr[0] = 0b11110000 | (val >> 18);
		arr[1] = (0b10000000 | (val >> 12)) & 0b10111111;
		arr[2] = (0b10000000 | (val >> 6)) & 0b10111111;
		arr[3] = (0b10000000 | val) & 0b10111111;
	}
	return (arr);
}

char			*encode_symbol(int val)
{
	short	nb;
	char	*s;

	nb = count_active_bits(val);
	if (nb <= 7 || (nb <= 8 && MB_CUR_MAX == 1))
	{
		s = ft_strnew(1);
		s[0] = val;
	}
	else
		s = utf8_encode(val, nb);
	if (!s)
		s = ft_strnew(0);
	return (s);
}

void			form_c_wide(t_fq *fq, va_list ap)
{
	int		val;

	val = va_arg(ap, int);
	fq->s = encode_symbol(val);
	fq->l = val ? ft_strlen(fq->s) : 1;
	if (fq->width > 1)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}

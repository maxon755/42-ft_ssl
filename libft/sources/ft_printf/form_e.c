/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 08:44:10 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/12 12:39:32 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		normalize_number(t_fq *fq)
{
	int power;

	power = 0;
	if (fq->n > 1 || fq->n <= 0)
	{
		while ((FT_ABS((intmax_t)fq->fn)) > 9)
		{
			fq->fn /= 10;
			power++;
		}
	}
	else
	{
		while ((intmax_t)fq->fn == 0)
		{
			fq->fn *= 10;
			power++;
		}
	}
	return (power);
}

void	add_exponent(t_fq *fq, int k)
{
	char *e;
	char *temp;
	char *ks;

	e = ft_strnew(4);
	e[0] = fq->type == 'e' ? 'e' : 'E';
	e[1] = fq->n >= 1 || fq->n <= 0 ? '+' : '-';
	if (k > 9)
		ks = ft_itoa(k);
	else
	{
		ks = ft_strnew(2);
		ks[0] = '0';
		ks[1] = '0' + k;
	}
	e = ft_strcat(e, ks);
	temp = fq->s;
	fq->s = ft_strjoin(fq->s, e);
	ft_strdel(&e);
	ft_strdel(&temp);
	ft_strdel(&ks);
}

void	form_e(t_fq *fq, va_list ap)
{
	int power;

	if (fq->size == L)
		fq->fn = va_arg(ap, long double);
	else
		fq->fn = va_arg(ap, double);
	fq->n = (intmax_t)fq->fn;
	power = normalize_number(fq);
	fq->s = ft_ftoa_abs(fq->fn, fq->precision == -1 ? 6 : fq->precision);
	add_exponent(fq, power);
	fq->l = ft_strlen(fq->s);
	if (fq->width > fq->l)
		compute_width_float(fq);
	else
	{
		add_sign_float(fq);
		compute_space(fq);
	}
	if (fq->flags[HOOK] == '1')
		*(ft_strchr(fq->s, '.')) = ',';
}

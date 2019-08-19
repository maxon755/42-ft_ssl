/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:33:23 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/12 15:25:39 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign_float(t_fq *fq)
{
	if (fq->fn < 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '-');
	if (fq->flags[PLUS] == '1' && fq->fn >= 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '+');
}

void	compute_width_float(t_fq *fq)
{
	if (fq->flags[MINUS] == '1')
	{
		add_sign_float(fq);
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	}
	else if (fq->flags[MINUS] == '0')
	{
		add_sign_float(fq);
		fq->s = fill_right(fq->s, fq->width, &(fq->l),
				fq->flags[ZERO] == 1 ? '0' : ' ');
	}
}

void	form_f(t_fq *fq, va_list ap)
{
	if (fq->size == L)
		fq->fn = va_arg(ap, long double);
	else
		fq->fn = va_arg(ap, double);
	fq->s = ft_ftoa_abs(fq->fn, fq->precision == -1 ? 6 : fq->precision);
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

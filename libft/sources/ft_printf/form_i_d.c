/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:29:24 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/28 15:59:28 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_sign(t_fq *fq)
{
	if (fq->n < 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '-');
	if (fq->flags[PLUS] == '1' && fq->n >= 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), '+');
}

void		compute_space(t_fq *fq)
{
	if (fq->flags[PLUS] == '0' && fq->flags[SPACE] == '1' && fq->n >= 0)
		fq->s = fill_right(fq->s, fq->l + 1, &(fq->l), ' ');
}

void		compute_precision(t_fq *fq)
{
	if (fq->precision == 0 && fq->n == 0)
	{
		free(fq->s);
		fq->s = ft_strnew(0);
		fq->l = 0;
	}
	else if (fq->precision > (int)fq->l)
		fq->s = fill_right(fq->s, fq->precision, &(fq->l), '0');
}

static void	get_value(t_fq *fq, va_list ap)
{
	if (fq->type == 'D')
	{
		fq->n = (va_arg(ap, long));
		return ;
	}
	if (fq->size == hh)
		fq->n = (char)(va_arg(ap, int));
	else if (fq->size == h)
		fq->n = (short)(va_arg(ap, int));
	else if (fq->size == ll)
		fq->n = va_arg(ap, long long);
	else if (fq->size == l)
		fq->n = (va_arg(ap, long));
	else if (fq->size == j)
		fq->n = (va_arg(ap, intmax_t));
	else if (fq->size == z)
		fq->n = (va_arg(ap, size_t));
	else
		fq->n = (va_arg(ap, int));
}

void		form_i_d(t_fq *fq, va_list ap)
{
	get_value(fq, ap);
	fq->s = ft_itoa_abs(fq->n);
	fq->l = ft_strlen(fq->s);
	if (fq->precision == 0 && fq->n == 0)
		compute_precision(fq);
	if (fq->precision >= (int)fq->width && fq->precision > (int)fq->l)
	{
		compute_precision(fq);
		add_sign(fq);
		compute_space(fq);
	}
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width(fq);
	else
	{
		add_sign(fq);
		compute_space(fq);
	}
}

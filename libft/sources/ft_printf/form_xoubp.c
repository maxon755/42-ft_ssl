/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_xoubp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:06:21 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/08 15:18:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			compute_precision_unsigned(t_fq *fq)
{
	if (fq->precision == 0 && fq->un == 0)
	{
		free(fq->s);
		fq->s = ft_strnew(0);
		fq->l = 0;
	}
	else if (fq->precision > (int)fq->l)
		fq->s = fill_right(fq->s, fq->precision, &(fq->l), '0');
}

static void		get_value(t_fq *fq, va_list ap)
{
	if (fq->size == hh)
		fq->un = (unsigned char)(va_arg(ap, unsigned int));
	else if (fq->size == h)
		fq->un = (unsigned short)(va_arg(ap, unsigned int));
	else if (fq->size == ll)
		fq->un = va_arg(ap, unsigned long long);
	else if (fq->size == l)
		fq->un = (va_arg(ap, unsigned long));
	else if (fq->size == j)
		fq->un = (va_arg(ap, uintmax_t));
	else if (fq->size == z)
		fq->un = (va_arg(ap, size_t));
	else
		fq->un = (va_arg(ap, unsigned int));
}

static void		get_string(t_fq *fq)
{
	if (fq->type == 'x')
		fq->s = ft_itoa_base_unsigned(fq->un, 16, 0);
	else if (fq->type == 'X')
		fq->s = ft_itoa_base_unsigned(fq->un, 16, 1);
	else if (fq->type == 'o' || fq->type == 'O')
		fq->s = ft_itoa_base_unsigned(fq->un, 8, 0);
	else if (fq->type == 'u' || fq->type == 'U')
		fq->s = ft_itoa_base_unsigned(fq->un, 10, 0);
	else if (fq->type == 'b')
		fq->s = ft_itoa_base_unsigned(fq->un, 2, 0);
}

void			form_xoubp(t_fq *fq, va_list ap)
{
	if (fq->type == 'U' || fq->type == 'O')
		fq->un = (va_arg(ap, unsigned long));
	else
		get_value(fq, ap);
	get_string(fq);
	fq->l = ft_strlen(fq->s);
	if ((fq->precision >= (int)fq->width && fq->precision > (int)fq->l) ||
		(fq->width == 0 && fq->precision == 0 && fq->un == 0))
	{
		compute_precision_unsigned(fq);
		if (((fq->type == 'x' || fq->type == 'X' || fq->type == 'b')
			&& fq->flags[HASH] == '1') &&
			!(fq->width == 0 && fq->precision == 0 && fq->un == 0))
			add_prefix(fq);
		if (((fq->type == 'o' || fq->type == 'O') && fq->flags[HASH] == '1')
			&& (fq->width == 0 && fq->precision == 0 && fq->un == 0))
			add_prefix(fq);
	}
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width_unsigned(fq);
	else if (fq->flags[HASH] == '1' && fq->un != 0)
		add_prefix(fq);
}

void			form_p(t_fq *fq, va_list ap)
{
	fq->un = (va_arg(ap, uintmax_t));
	fq->s = ft_itoa_base_unsigned(fq->un, 16, 0);
	fq->l = ft_strlen(fq->s);
	if ((fq->precision >= (int)fq->width && fq->precision > (int)fq->l) ||
		(fq->width == 0 && fq->precision == 0 && fq->un == 0))
	{
		compute_precision_unsigned(fq);
		add_prefix(fq);
	}
	else if ((int)fq->width > fq->precision && fq->width > fq->l)
		compute_width_unsigned(fq);
	else
		add_prefix(fq);
}

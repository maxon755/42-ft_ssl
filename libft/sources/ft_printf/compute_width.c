/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:28:02 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/29 19:28:04 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_sign(t_fq *fq)
{
	if (fq->n < 0)
		fq->s[0] = '-';
	if (fq->flags[PLUS] == '1' && fq->n >= 0)
		fq->s[0] = '+';
}

static void	handle_minus_1(t_fq *fq)
{
	if (fq->flags[MINUS] == '1')
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	else
		fq->s = fill_right(fq->s, fq->width, &(fq->l), ' ');
}

static void	handle_minus_2(t_fq *fq, int t)
{
	if (fq->flags[MINUS] == '1')
	{
		add_sign(fq);
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	}
	else
	{
		if ((size_t)fq->precision > fq->l)
			fq->s = fill_right(fq->s, fq->width, &(fq->l), t ? ' ' : ('0'));
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l), ' ');
		set_sign(fq);
		if (fq->flags[SPACE] == '1' && fq->flags[PLUS] == '0')
			fq->s[0] = ' ';
	}
}

void		compute_width(t_fq *fq)
{
	int t;

	t = 0;
	fq->l = ft_strlen(fq->s);
	if (fq->precision > (int)fq->l)
	{
		t = 1;
		compute_precision(fq);
	}
	if (fq->flags[ZERO] == '0')
	{
		add_sign(fq);
		handle_minus_1(fq);
	}
	else if (fq->flags[ZERO] == '1')
		handle_minus_2(fq, t);
}

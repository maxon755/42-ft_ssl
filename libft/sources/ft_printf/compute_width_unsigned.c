/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_width_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:32:08 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/01 20:32:12 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_prefix(t_fq *fq)
{
	char *temp;
	char prefix[3];

	prefix[0] = '0';
	prefix[2] = '\0';
	if (fq->type == 'x' || fq->type == 'p')
		prefix[1] = 'x';
	else if (fq->type == 'X')
		prefix[1] = 'X';
	else if (fq->type == 'b')
		prefix[1] = 'b';
	else
		prefix[1] = '\0';
	temp = fq->s;
	fq->s = ft_strjoin(prefix, fq->s);
	fq->l = ft_strlen(fq->s);
	free(temp);
}

void		set_prefix(t_fq *fq)
{
	if (fq->type == 'x' || fq->type == 'p')
		fq->s[1] = 'x';
	else if (fq->type == 'X')
		fq->s[1] = 'X';
}

static void	handle_minus_1(t_fq *fq)
{
	if (fq->flags[MINUS] == '1' && fq->width > fq->l)
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	else if (fq->flags[MINUS] == '0')
		fq->s = fill_right(fq->s, fq->width, &(fq->l), ' ');
}

static void	handle_minus_2(t_fq *fq, int t)
{
	if (fq->flags[MINUS] == '1')
	{
		if (fq->flags[HASH] == '1' && fq->un != 0)
			add_prefix(fq);
		fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
	}
	else
	{
		fq->s = fill_right(fq->s, fq->width, &(fq->l), t ? ' ' : ('0'));
		if ((fq->flags[HASH] == '1' && fq->un != 0) || fq->type == 'p')
			set_prefix(fq);
	}
}

void		compute_width_unsigned(t_fq *fq)
{
	int t;

	t = 0;
	fq->l = ft_strlen(fq->s);
	if ((fq->precision > (int)fq->l) || (fq->precision == 0 && fq->un == 0))
	{
		t = 1;
		compute_precision_unsigned(fq);
	}
	if (fq->flags[ZERO] == '0')
	{
		if ((fq->flags[HASH] == '1' && fq->un != 0) || fq->type == 'p')
			add_prefix(fq);
		handle_minus_1(fq);
	}
	else if (fq->flags[ZERO] == '1')
	{
		handle_minus_2(fq, t);
	}
}

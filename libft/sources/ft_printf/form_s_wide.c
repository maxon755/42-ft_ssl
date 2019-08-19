/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_s_wide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:26:00 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/08 09:58:29 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	wstr_len(wchar_t *wstr)
{
	size_t len;

	len = 0;
	while (wstr[len])
		len++;
	return (len);
}

static void		get_wstr(t_fq *fq)
{
	size_t	i;
	size_t	len;
	char	*w_temp;

	len = wstr_len(fq->p);
	i = 0;
	fq->s = ft_strnew(len * 4 + 1);
	while (i < len)
	{
		w_temp = encode_symbol(fq->p[i]);
		fq->s = ft_strcat(fq->s, w_temp);
		free(w_temp);
		i++;
	}
	fq->l = ft_strlen(fq->s);
}

static int		clarify_precision(t_fq *fq)
{
	int		sum;
	int		n;
	size_t	i;

	i = 0;
	sum = 0;
	while (i < fq->l)
	{
		if (!(((unsigned char)fq->s[i] >> 3) ^ 0b00011110))
			n = 4;
		else if (!(((unsigned char)fq->s[i] >> 4) ^ 0b00001110))
			n = 3;
		else if (!(((unsigned char)fq->s[i] >> 5) ^ 0b00000110))
			n = 2;
		else
			n = 1;
		sum += n;
		if ((int)i + n <= fq->precision)
			i += n;
		else
			return (sum - n);
	}
	return (0);
}

void			form_s_wide(t_fq *fq, va_list ap)
{
	char	*t;

	fq->p = va_arg(ap, wchar_t *);
	if (fq->p)
		get_wstr(fq);
	else
		fq->s = ft_strdup("(null)");
	fq->l = ft_strlen(fq->s);
	if (fq->precision >= 0 && fq->precision < (int)fq->l)
	{
		t = fq->s;
		fq->precision = clarify_precision(fq);
		fq->s = ft_strsub(fq->s, 0, fq->precision);
		fq->l = fq->precision;
		ft_strdel(&t);
	}
	if (fq->width > fq->l)
	{
		if (fq->flags[MINUS] == '1')
			fq->s = fill_left(fq->s, fq->width, &(fq->l), ' ');
		else
			fq->s = fill_right(fq->s, fq->width, &(fq->l),
					fq->flags[ZERO] == '1' ? '0' : ' ');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   former.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:29:41 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/27 09:26:15 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_left(char *s, size_t width, size_t *len, char c)
{
	char	*t;
	size_t	i;

	t = ft_strnew(width);
	i = 0;
	while (i < width)
	{
		if (i < *len)
			t[i] = s[i];
		else
			t[i] = c;
		i++;
	}
	*len = width;
	free(s);
	return (t);
}

char	*fill_right(char *s, size_t width, size_t *len, char c)
{
	char	*t;
	size_t	i;
	size_t	diff;

	t = ft_strnew(width);
	diff = width - *len;
	i = 0;
	while (i < width)
	{
		if (i < diff)
			t[i] = c;
		else
			t[i] = s[i - diff];
		i++;
	}
	*len = width;
	free(s);
	return (t);
}

int		form_output(va_list ap, t_fq *fq)
{
	if (fq->type == 's' && fq->size != l)
		form_s(fq, ap);
	else if (fq->type == 'S' || (fq->type == 's' && fq->size == l))
		form_s_wide(fq, ap);
	else if (fq->type == 'c' && fq->size != l)
		form_c(fq, ap);
	else if (fq->type == 'C' || (fq->type == 'c' && fq->size == l))
		form_c_wide(fq, ap);
	else if (fq->type == 'i' || fq->type == 'd' || fq->type == 'D')
		form_i_d(fq, ap);
	else if (fq->type == 'x' || fq->type == 'X' || fq->type == 'o' ||
			fq->type == 'O' || fq->type == 'u' || fq->type == 'U' ||
			fq->type == 'b')
		form_xoubp(fq, ap);
	else if (fq->type == 'p')
		form_p(fq, ap);
	else if (fq->type == '%')
		form_elips(fq);
	else if (fq->type == 'r')
		form_r(fq, ap);
	else if (fq->type == 'f' || fq->type == 'F')
		form_f(fq, ap);
	else if (fq->type == 'e' || fq->type == 'E')
		form_e(fq, ap);
	return (0);
}

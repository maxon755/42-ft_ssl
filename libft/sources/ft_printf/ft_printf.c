/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:51:42 by mgayduk           #+#    #+#             */
/*   Updated: 2019/07/31 18:39:34 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Goes through the format string, looking for the % symbol
** If % was found - parse qualifier by filling struct fq;
** Then next ap will be written on stdout;
*/

static void	init_struct(t_fq *fq)
{
	ft_memset(fq->flags, '0', 6);
	fq->flags[6] = '\0';
	fq->width = 0;
	fq->precision = -1;
	fq->size = 0;
	fq->type = '\0';
	fq->indent = 0;
	fq->s = NULL;
	fq->l = 0;
	fq->p = NULL;
	fq->n = 0;
	fq->un = 0;
}

void		write_counter(va_list ap, t_fq *fq, int count)
{
	void *dest;

	dest = va_arg(ap, void *);
	if (fq->size == hh)
		*((signed char *)dest) = count;
	else if (fq->size == h)
		*((short int *)dest) = count;
	else if (fq->size == l)
		*((long int *)dest) = count;
	else if (fq->size == ll)
		*((long long int *)dest) = count;
	else if (fq->size == j)
		*((intmax_t *)dest) = count;
	else if (fq->size == z)
		*((size_t *)dest) = count;
	else
		*((int *)dest) = count;
}

void		execute_qualifier(t_fq *fq, va_list ap, int *count)
{
	if (fq->type == 'n')
		write_counter(ap, fq, *count);
	else if (fq->type == '&')
		fq->fd = va_arg(ap, int);
	else if (fq->type == 'k')
		*count += print_date(fq);
	else if (fq->type)
	{
		if (fq->type != 't')
			form_output(ap, fq);
		*count += write(fq->fd, fq->s, fq->l);
		free(fq->s);
	}
}

void		perform(const char *format, va_list ap, int *count)
{
	const char	*needle;
	const char	*fiber;
	size_t		len;
	t_fq		fq;

	fq.fd = 1;
	fiber = format;
	while ((needle = ft_strchr(fiber, '%')))
	{
		if (needle != fiber)
		{
			*count += (needle - fiber);
			write(fq.fd, fiber, needle - fiber);
		}
		init_struct(&fq);
		parse_qualifier(needle, &fq, ap);
		execute_qualifier(&fq, ap, count);
		needle += fq.indent;
		fiber = needle;
	}
	write(fq.fd, fiber, (len = ft_strlen(fiber)));
	*count += len;
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, format);
	perform(format, ap, &count);
	va_end(ap);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:24:12 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/01 16:49:35 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char **qual, t_fq *fq)
{
	char			*type;

	if ((type = ft_strchr(TYPES, **qual)))
	{
		fq->type = *type;
		return (1);
	}
	return (0);
}

static int	check_flags(char **q_str, t_fq *fq)
{
	char		*tmp;

	if ((tmp = ft_strchr(FV, **q_str)))
	{
		fq->flags[tmp - FV] = '1';
		(*q_str)++;
		return (1);
	}
	return (0);
}

void		parse_qualifier(const char *qual, t_fq *fq, va_list ap)
{
	char *q_str;

	q_str = (char *)qual + 1;
	while (*q_str)
	{
		if (!(check_flags(&q_str, fq) ||
		check_width(&q_str, fq, ap) ||
		check_precision(&q_str, fq, ap) ||
		check_size(&q_str, fq) ||
		check_type(&q_str, fq)))
		{
			form_issue_out(fq, *q_str);
			break ;
		}
		else if (fq->type)
			break ;
	}
	if (fq->type)
		fq->indent = q_str - qual + 1;
	else
		fq->indent = q_str - qual;
}

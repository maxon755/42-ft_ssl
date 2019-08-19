/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksim.gayduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:07:46 by mgayduk           #+#    #+#             */
/*   Updated: 2018/05/22 21:57:16 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && !*alst && new)
		*alst = new;
	else if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

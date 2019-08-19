/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:19:13 by mgayduk           #+#    #+#             */
/*   Updated: 2018/01/04 10:50:30 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list *alst, t_list *new)
{
	if (!alst && new)
		return (new);
	if (alst && new)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
		new->next = NULL;
	}
	return (new);
}

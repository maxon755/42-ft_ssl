/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:40:08 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 17:20:46 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			temp = (*alst)->next;
			free(*alst);
			*alst = NULL;
			*alst = temp;
		}
	}
}

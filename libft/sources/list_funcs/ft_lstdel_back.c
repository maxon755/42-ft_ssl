/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:49:25 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 17:21:51 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_node(t_list *node)
{
	if (node->content)
	{
		free(node->content);
		node->content = NULL;
	}
	node->content_size = 0;
}

void		ft_lstdel_back(t_list **alst)
{
	t_list *temp;
	t_list *track;

	if (alst && (*alst) && (*alst)->next)
	{
		track = *alst;
		while (track->next)
		{
			temp = track;
			track = track->next;
		}
		ft_clear_node(track);
		free(track);
		track = NULL;
		temp->next = NULL;
	}
	else if (alst && (*alst) && !((*alst)->next))
	{
		ft_clear_node(*alst);
		free(*alst);
		*alst = NULL;
	}
}

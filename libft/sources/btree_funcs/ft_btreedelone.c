/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:11:47 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/16 12:11:54 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btreedelone(t_btree **abtree, void (*del)(void *, size_t))
{
	if (abtree && *abtree && del)
	{
		(*del)((*abtree)->content, (*abtree)->content_size);
		free(*abtree);
		*abtree = NULL;
	}
}

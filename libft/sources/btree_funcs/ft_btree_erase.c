/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:58:09 by mgayduk           #+#    #+#             */
/*   Updated: 2018/06/01 16:55:55 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_erase(t_btree **root, void (*del)(void *, size_t))
{
	if (!(*root))
		return ;
	ft_btree_erase(&((*root)->left), del);
	ft_btree_erase(&((*root)->right), del);
	if (!(*root)->right && !(*root)->left)
	{
		del((*root)->content, (*root)->content_size);
		free(*root);
		*root = NULL;
		return ;
	}
}

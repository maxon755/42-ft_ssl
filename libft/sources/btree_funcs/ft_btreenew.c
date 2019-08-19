/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:34:08 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/16 11:34:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(void const *content, size_t content_size)
{
	t_btree	*new_node;

	new_node = (t_btree *)malloc(sizeof(t_btree));
	if (!new_node)
		return (NULL);
	if (!content)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		new_node->content = ft_memalloc(content_size);
		if (!(new_node->content))
		{
			free(new_node);
			return (NULL);
		}
		ft_memcpy(new_node->content, content, content_size);
		new_node->content_size = content_size;
	}
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

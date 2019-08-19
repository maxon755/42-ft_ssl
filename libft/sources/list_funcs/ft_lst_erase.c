/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:18:31 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/15 16:02:05 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_erase(t_list *head)
{
	t_list *temp;

	if (!head)
		return (NULL);
	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->content)
		{
			free(temp->content);
			temp->content = NULL;
		}
		temp->content_size = 0;
		free(temp);
	}
	return (NULL);
}

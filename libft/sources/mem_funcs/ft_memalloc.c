/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:20:43 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/10 14:27:43 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*temp;

	if (size == 0)
		return (NULL);
	temp = (char *)malloc(size);
	if (temp)
	{
		i = 0;
		while (i < size)
		{
			temp[i] = 0;
			i++;
		}
		return ((void *)temp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:00:45 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 17:42:11 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char			*temp;
	unsigned char	const	*s;

	if (dst <= src)
	{
		temp = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp = (unsigned char *)dst;
		temp += len;
		s = (unsigned char	const *)src;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}

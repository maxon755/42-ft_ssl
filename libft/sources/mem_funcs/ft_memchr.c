/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:00:50 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/11 20:19:45 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char const *temp;

	temp = (unsigned char const *)s;
	while (n--)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}

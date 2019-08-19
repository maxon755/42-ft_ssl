/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:38:41 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/15 09:42:47 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	s = s + len;
	len++;
	while (len)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:52:00 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 10:32:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	len2;

	if (!(*needle))
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (*haystack && len >= len2)
	{
		if (*haystack == *needle &&
			!ft_memcmp(haystack, needle, len2))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

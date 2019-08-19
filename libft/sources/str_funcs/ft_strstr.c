/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:10:05 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/08 16:49:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (ft_strnequ(haystack, needle, ft_strlen(needle)))
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

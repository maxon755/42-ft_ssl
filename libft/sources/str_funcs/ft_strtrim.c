/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:07:54 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/15 11:00:15 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t		len;
	char const	*end;
	char		*str;

	if (!s)
		return (NULL);
	end = s + ft_strlen(s) - 1;
	while (ft_iswhite(*s))
		s++;
	while (ft_iswhite(*end) && end > s)
		end--;
	len = end - s + 1;
	str = ft_strnew(len);
	if (str)
	{
		while (s <= end)
			*str++ = *s++;
		return (str - len);
	}
	return (NULL);
}

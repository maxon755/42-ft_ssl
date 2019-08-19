/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:05:45 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/11 19:59:42 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *dest;
	char *start;

	if (!s1)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1));
	if (!dest)
		return (NULL);
	start = dest;
	while ((*dest++ = *s1++))
		;
	return (start);
}

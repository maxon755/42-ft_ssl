/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:28:03 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/09 13:41:33 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	if (!s1)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	i = 0;
	j = start;
	while (j < start + len)
	{
		sub[i] = s1[j];
		i++;
		j++;
	}
	return (sub);
}

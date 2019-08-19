/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:17:58 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/09 18:58:10 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		i = 0;
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}

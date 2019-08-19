/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:22:58 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/15 09:38:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = ft_strnew(ft_strlen(s));
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:16:38 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/09 11:27:48 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char *t1;
	unsigned char *t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (n--)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	return (0);
}

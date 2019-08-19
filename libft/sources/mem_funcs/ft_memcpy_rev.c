/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:36:46 by maks              #+#    #+#             */
/*   Updated: 2019/08/14 11:39:24 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char			*s1;
	char			*s2;
	unsigned int	i;
	unsigned int	j;

	if (n == 0 || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	j = n - 1;
	while (i < n)
	{
		s1[i] = s2[j];
		i++;
		j--;
	}
	return (dst);
}

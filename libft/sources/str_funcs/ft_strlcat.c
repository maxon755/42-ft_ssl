/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:52:56 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/14 14:44:20 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t temp;

	temp = dstsize;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > ft_strlen(dst))
	{
		dstsize -= 1;
		while (*dst && dstsize--)
			dst++;
		while (dstsize-- && (*dst++ = *src++))
			;
		*dst = '\0';
	}
	dstsize = temp;
	return ((dstsize < dst_len) ? dstsize + src_len : dst_len + src_len);
}

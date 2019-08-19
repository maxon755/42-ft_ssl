/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:47:01 by mgayduk           #+#    #+#             */
/*   Updated: 2018/02/02 10:56:44 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(uintmax_t n, char base)
{
	size_t len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char			*ft_itoa_base_unsigned(uintmax_t n, char base, int char_case)
{
	uintmax_t	num;
	char		temp;
	size_t		len;
	char		*str;

	num = n;
	len = ft_get_len(n, base);
	str = ft_strnew(len);
	if (n == 0)
		str[0] = '0';
	len--;
	while (num)
	{
		temp = num % base;
		if (temp <= 9)
			str[len] = temp + '0';
		else
			str[len] = temp - 10 + (char_case == 1 ? 'A' : 'a');
		num /= base;
		len--;
	}
	return (str);
}

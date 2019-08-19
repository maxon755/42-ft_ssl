/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <maksim.gayduk@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:38:16 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/19 13:33:21 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	int		trig;
	size_t	word_count;

	trig = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && !trig)
		{
			word_count++;
			trig = 1;
		}
		if (*s == c && trig)
			trig = 0;
		s++;
	}
	return (word_count);
}

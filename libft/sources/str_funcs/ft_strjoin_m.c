/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:46:47 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/14 11:39:54 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_m(char *s1, char *s2, int mode)
{
	char *joined;

	joined = ft_strjoin(s1, s2);
	if (mode == FT_FREE_FIRST || mode == FT_FREE_BOTH)
	{
		free(s1);
	}
	if (mode == FT_FREE_SECOND || mode == FT_FREE_BOTH)
	{
		free(s2);
	}
	return (joined);
}

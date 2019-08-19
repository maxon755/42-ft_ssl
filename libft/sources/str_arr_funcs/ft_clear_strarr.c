/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_strarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:11:26 by mgayduk           #+#    #+#             */
/*   Updated: 2017/12/29 13:32:52 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_strarr(char ***str_arr)
{
	size_t	i;
	char	**tmp;

	if (!(*str_arr))
		return ;
	tmp = *str_arr;
	i = 0;
	while (tmp[i])
	{
		ft_strclr(tmp[i]);
		ft_strdel(&tmp[i]);
		i++;
	}
	free(*str_arr);
	*str_arr = NULL;
}

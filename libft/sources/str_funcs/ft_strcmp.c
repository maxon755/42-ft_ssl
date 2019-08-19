/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:46:57 by mgayduk           #+#    #+#             */
/*   Updated: 2017/11/13 11:07:23 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char const *s1, char const *s2)
{
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

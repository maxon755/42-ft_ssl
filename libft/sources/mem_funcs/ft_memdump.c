/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:19:36 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/02 15:25:09 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_header(void)
{
	size_t	i;

	i = 0;
	while (i < FT_DUMP_SIZE)
	{
		if (i % FT_DUMP_SIZE == 0)
			ft_printf("*\t", i / FT_DUMP_SIZE);
		ft_printf("%02hhi ", i);
		i++;
		if (i % FT_DUMP_CHUNK == 0 && i % FT_DUMP_SIZE != 0)
			ft_printf("	");
		if (i % FT_DUMP_SIZE == 0)
			ft_printf("\n");
	}
}

void		ft_memdump(void *ptr, size_t mem_size)
{
	size_t			i;
	unsigned char	*s;

	if (ptr == NULL)
		return ;
	s = (unsigned char *)ptr;
	i = 0;
	print_header();
	while (i < mem_size)
	{
		if (i % FT_DUMP_SIZE == 0)
			ft_printf("%i\t", i / FT_DUMP_SIZE);
		ft_printf("%02hhx ", s[i]);
		i++;
		if (i % FT_DUMP_CHUNK == 0 && i % FT_DUMP_SIZE != 0)
			ft_printf("	");
		if (i % FT_DUMP_SIZE == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

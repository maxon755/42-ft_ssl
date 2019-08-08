/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_input_stream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:27:20 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/08 19:23:27 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void hash_input_stream(void)
{
    char            *input_str;
    char            *tmp_str;
    char            buffer[MD5_BLOCK_SIZE];
	ssize_t			readed;


    input_str = ft_strnew(0);
	while ((readed = read(STDIN_FILENO, buffer, MD5_BLOCK_SIZE)) > 0)
	{
        tmp_str = ft_strnew(readed);
        ft_memcpy(tmp_str, buffer, readed);
        ft_printf("readed: %i byte, %s\n", readed, tmp_str);
        input_str = ft_strjoin_m(input_str, tmp_str, FT_FREE_BOTH);
        
	}

    ft_printf("result string: %s\n", input_str);
    hash_string(input_str);
}

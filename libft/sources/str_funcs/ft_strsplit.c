/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayduk <mgayduk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:51:29 by mgayduk           #+#    #+#             */
/*   Updated: 2018/03/13 18:38:29 by mgayduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_word	ft_find_word(char const *s, char c)
{
	int		trig;
	t_word	word;

	word.start = NULL;
	word.end = NULL;
	trig = 0;
	while (!word.start || !word.end)
	{
		if (*s != c && !trig)
		{
			word.start = s;
			trig = 1;
		}
		if ((*s == c || *s == '\0') && trig)
			word.end = s;
		s++;
	}
	word.len = word.end - word.start;
	return (word);
}

static char		**ft_dissolution(char **arr, size_t len)
{
	size_t i;

	i = 0;
	while (i < len + 1)
	{
		ft_strclr(arr[i]);
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	word_count;
	char	**arr;
	t_word	word;
	char	*temp;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	if (!(arr = (char **)(ft_memalloc(sizeof(char *) * (word_count + 1)))))
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		word = ft_find_word(s, c);
		temp = ft_strnew(word.len);
		if (!temp)
			return (ft_dissolution(arr, word_count));
		s = word.start;
		while (s < word.end && (*temp++ = *s++))
			;
		arr[i] = temp - word.len;
		i++;
	}
	return (arr);
}

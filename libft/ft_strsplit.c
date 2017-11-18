/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:23:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:23:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
	}
	return (words);
}

static int		ft_free_words(char ***res, size_t i)
{
	while (i--)
		ft_strdel(&(*res[i]));
	free(*res);
	*res = NULL;
	return (1);
}

static char		**ft_strsplit_kernel(char *s, char c, size_t words)
{
	size_t	i;
	char	**res;
	char	*word;

	i = 0;
	if ((res = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
	{
		while (i < words)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				word = s;
				while (*s != c && *s)
					s++;
				*s = '\0';
				if (!(res[i++] = ft_strdup(word)) && ft_free_words(&res, i))
					return (NULL);
				s++;
			}
		}
		res[i] = NULL;
	}
	return (res);
}

char			**ft_strsplit(char const *str, char c)
{
	char	*s;

	if (!str || !(s = ft_strdup((char *)str)))
		return (NULL);
	return (ft_strsplit_kernel(s, c, ft_count_words(s, c)));
}

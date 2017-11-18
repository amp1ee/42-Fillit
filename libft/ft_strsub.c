/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:47:50 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/13 15:10:28 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	if (s && len <= ft_strlen(s)
			&& (res = (char *)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (len)
		{
			res[i++] = s[start++];
			len--;
		}
		res[i] = '\0';
	}
	return (res);
}

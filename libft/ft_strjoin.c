/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:15:57 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:15:58 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	char *backup;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)ft_memalloc(sizeof(char)
							* (ft_strlen(s1) + ft_strlen(s2) + 1));
	backup = res;
	if (res)
	{
		while (*s1)
			*res++ = *s1++;
		while (*s2)
			*res++ = *s2++;
		*res = '\0';
	}
	return (backup);
}

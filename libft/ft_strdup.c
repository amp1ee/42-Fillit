/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:34:22 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:34:24 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	if ((res = (char *)ft_memalloc(sizeof(char) * (ft_strlen(src) + 1))))
	{
		i = 0;
		while (src[i])
		{
			res[i] = src[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

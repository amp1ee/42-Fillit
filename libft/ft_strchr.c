/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:53:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:53:31 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)str;
	while (i <= ft_strlen(str))
	{
		if (res[i] == ch)
			return ((res + i));
		i++;
	}
	return (NULL);
}

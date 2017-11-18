/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:46:44 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:46:45 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	res = NULL;
	if (s && f && (res = (char *)ft_memalloc(sizeof(char)
									* (ft_strlen(s) + 1))))
	{
		i = 0;
		while (s[i])
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

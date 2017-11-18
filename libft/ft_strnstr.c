/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:15:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:15:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	j;
	size_t	i;

	b = (char *)big;
	if (!ft_strlen(little))
		return (b);
	i = 0;
	while (b[i] && i <= len - ft_strlen(little) && !(len < ft_strlen(little)))
	{
		j = 0;
		while (little[j] && little[j] == b[i + j]
			&& (i + j < len))
			j++;
		if (j == ft_strlen(little))
			return (&b[i]);
		i++;
	}
	return (NULL);
}

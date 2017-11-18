/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:15:06 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:15:13 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	size_t	i;
	size_t	j;

	b = (char *)big;
	if (!ft_strlen(little))
		return (b);
	i = 0;
	while (b[i])
	{
		j = 0;
		while (little[j] && little[j] == b[i + j])
			j++;
		if (j == ft_strlen(little))
			return (&b[i]);
		i++;
	}
	return (NULL);
}

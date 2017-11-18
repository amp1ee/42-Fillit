/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:32:29 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/13 15:45:22 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	c;

	if (!s || !(*s))
		return (s);
	i = -1;
	len = ft_strlen(s);
	while (++i < --len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
	}
	return (s);
}

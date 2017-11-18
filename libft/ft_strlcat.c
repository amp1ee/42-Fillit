/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:53:15 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:53:16 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*s;
	size_t	n;
	size_t	dest_len;

	s = (char *)src;
	n = size;
	dest_len = ft_strlen(dest);
	while (n && *dest && dest++)
		n--;
	if (n == 0)
		return (size + ft_strlen(s));
	while (*s && n != 1)
	{
		*dest++ = *s++;
		n--;
	}
	*dest = '\0';
	return (dest_len + ft_strlen(src));
}

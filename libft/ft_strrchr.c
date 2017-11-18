/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:53:45 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:53:46 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *res;

	res = (char *)str + ft_strlen(str);
	while (res >= str)
	{
		if (*res == ch)
			return (res);
		res--;
	}
	return (NULL);
}

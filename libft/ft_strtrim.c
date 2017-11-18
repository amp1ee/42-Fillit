/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:41:31 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/07 22:41:32 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	spaces;
	size_t	start;
	size_t	finish;
	size_t	i;

	i = 0;
	spaces = 0;
	start = 0;
	if (!s)
		return (NULL);
	while ((ft_isblank(s[start]) || s[start] == '\n') && ++spaces)
		start++;
	finish = ft_strlen(s);
	while (finish && (s[finish - 1] == ' ' || s[finish - 1] == '\n'
							|| s[finish - 1] == '\t') && finish--)
		spaces++;
	res = (char *)ft_memalloc(sizeof(char)
					* ((finish > start) ? (finish - start + 1) : 1));
	if (!res)
		return (NULL);
	while (start < finish)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

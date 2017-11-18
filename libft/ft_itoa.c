/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:25:21 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:25:22 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_kernel(int n, int minus, int digits)
{
	char *res;

	if ((res = (char *)ft_memalloc(sizeof(char) * (digits + 1))))
	{
		res[digits--] = '\0';
		while (digits >= minus)
		{
			res[digits--] = (n % 10) + '0';
			n /= 10;
		}
		if (minus)
			res[0] = '-';
	}
	return (res);
}

char			*ft_itoa(int n)
{
	int digits;
	int number;
	int minus;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = 0;
	digits = 1;
	number = n;
	while ((number /= 10))
		digits++;
	if (n < 0)
	{
		n = -n;
		digits++;
		minus = 1;
	}
	return (ft_itoa_kernel(n, minus, digits));
}

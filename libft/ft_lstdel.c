/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:06 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:24:07 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *delete;

	if (del && alst)
	{
		while (*alst)
		{
			delete = *alst;
			(*del)(delete->content, delete->content_size);
			free(delete);
			delete = NULL;
			*alst = (*alst)->next;
		}
	}
}

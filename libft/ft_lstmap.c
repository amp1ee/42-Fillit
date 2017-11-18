/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:24:50 by vbrazhni          #+#    #+#             */
/*   Updated: 2017/11/08 22:24:51 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *el;
	t_list *res;
	t_list *prev;
	t_list *head;

	prev = NULL;
	head = NULL;
	if (f)
	{
		while (lst)
		{
			el = (*f)(lst);
			res = ft_lstnew(el->content, el->content_size);
			if (prev)
				prev->next = res;
			else
				head = res;
			lst = lst->next;
			prev = res;
		}
	}
	return (head);
}

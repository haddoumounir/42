/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:59 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:11:19 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pla;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	pla = ft_lstnew(f(lst->content));
	if (!pla)
		return (0);
	temp = pla;
	lst = lst->next;
	while (lst)
	{
		pla->next = ft_lstnew(f(lst->content));
		if (!pla->next)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		pla = pla->next;
		lst = lst->next;
	}
	pla->next = NULL;
	return (temp);
}

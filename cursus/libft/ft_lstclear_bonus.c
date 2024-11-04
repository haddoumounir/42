/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:06:47 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:46 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_happy(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (!(del) || !(lst))
		return ;
	curr = *lst;
	while (curr)
	{
		tmp = curr->next;
		ft_happy(curr, del);
		free(curr);
		curr = tmp;
	}
	*lst = NULL;
}

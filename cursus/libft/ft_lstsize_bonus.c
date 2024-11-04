/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:31:23 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:09 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!!lst)
	{
		while (!!(lst->next) && ++i)
			lst = lst->next;
		i += 1;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*str;
	t_list	*s;
	t_list	*j;

	str = ft_lstnew("mew");
	s = ft_lstnew("mewss");
	j = ft_lstnew("mewss");
	str->next = s;
	s->next = j;
	j->next = NULL;
	printf("%d \n", ft_lstsize(str));
	return (0);
}
*/
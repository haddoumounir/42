/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:05:21 by mhaddou           #+#    #+#             */
/*   Updated: 2024/10/27 18:14:04 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}
/*

int	main(void)
{
	t_list	**cars;

	cars[0] = ft_lstnew("sayara fa5iirrra hhhhhhhh");
	printf("%s \n", cars[0]->content);
	printf("%s \n", cars[0]->next);
	ft_lstadd_front(cars, ft_lstnew("9alk chi bmw"));
	printf("%s \n", cars[0]->content);
	printf("%s \n", cars[0]->next->next);
	return (0);
}
*/
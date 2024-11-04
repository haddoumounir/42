/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:51:53 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:43 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*moew;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	moew = *lst;
	while (moew->next)
		moew = moew->next;
	moew->next = new;
}

/*
int	main(void)
{
	t_list	**str;
	t_list	*cat;

	str[0] = ft_lstnew("hellog");
	cat = ft_lstnew("hellog");
	printf("%s \n", str[0]->content);
	printf("%s \n", str[0]->next);
	// ft_lstadd_back(str,cat);
	// printf("%s \n",str[0]->content);
	return (0);
}
*/

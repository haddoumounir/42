/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:54:52 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/22 19:41:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_mem_block	**get_alloc_list(void)
{
	static t_mem_block	*alloc_list;

	return (&alloc_list);
}

t_data	*data_giver(t_data *data)
{
	static t_data	*ptr;

	if (data)
		ptr = data;
	return (ptr);
}

void	*ft_malloc(size_t size)
{
	void		*ptr;
	t_mem_block	*new_block;
	t_mem_block	**alloc_list;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd(CAM, 2);
		get_promot(data_giver(NULL));
	}
	new_block = malloc(sizeof(t_mem_block));
	if (!new_block)
	{
		ft_putstr_fd(CAM, 2);
		get_promot(data_giver(NULL));
	}
	new_block->ptr = ptr;
	alloc_list = get_alloc_list();
	new_block->next = *alloc_list;
	*alloc_list = new_block;
	return (ptr);
}

void	ft_free(void)
{
	t_mem_block	**alloc_list;
	t_mem_block	*current;
	t_mem_block	*temp;

	alloc_list = get_alloc_list();
	current = *alloc_list;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->ptr);
		free(temp);
	}
	*alloc_list = NULL;
}

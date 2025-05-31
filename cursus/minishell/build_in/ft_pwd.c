/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:01:17 by obajali           #+#    #+#             */
/*   Updated: 2025/07/15 13:09:43 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(t_data *data)
{
	if (!data->cwd)
	{
		data->cwd = getcwd(NULL, 0);
		if (!data->cwd)
			perror(GETCWD);
		return (1);
	}
	ft_putstr_fd(ft_strjoin(data->cwd, "\n"), 1);
	return (0);
}

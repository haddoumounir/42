/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:27:41 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:33 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_option(char **arguments, int *flag)
{
	int	i;
	int	j;

	i = 1;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '-')
		{
			j++;
			while (arguments[i][j] == 'n')
				j++;
			if (!arguments[i][j])
				*flag = 1;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

int	ft_echo(t_box *cmd)
{
	int	flag;
	int	i;

	flag = 0;
	i = check_option(cmd->arguments, &flag);
	while (cmd->arguments[i])
	{
		ft_putstr_fd(cmd->arguments[i], 1);
		if (cmd->arguments[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	return (0);
}

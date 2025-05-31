/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:01:28 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:49 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*check_numeric(char *str)
{
	int	i;
	int	d;
	int	j;
	int	*arr;

	i = 0;
	d = 0;
	j = 0;
	arr = (int *)ft_malloc(sizeof(int) * 3);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		(arr[2] = 1 * (str[i++] == '-'));
	while (str[i] == '0')
		i++;
	while (str[i + j])
	{
		if (!ft_isdigit(str[i + j]))
			return ((arr[0] = -1, arr));
		d++;
		j++;
	}
	arr[0] = d;
	arr[1] = i;
	return (arr);
}

void	error_exit(char *arg)
{
	char	*tmp;

	tmp = "minishell: exit: ";
	tmp = ft_strjoin(tmp, arg);
	ft_putstr_fd(ft_strjoin(tmp, NAC), 2);
}

unsigned char	check_valid(int *arr, char *str)
{
	char	*num;
	char	*num_n;

	num = "9223372036854775807";
	num_n = "9223372036854775808";
	if (arr[0] == 19)
	{
		if (arr[2] == 1)
		{
			if (ft_strcmp(str + arr[1], num_n) > 0)
				return (2);
		}
		else
		{
			if (ft_strcmp(str + arr[1], num) > 0)
				return (2);
		}
	}
	return (ft_atoi(str));
}

void	free_exit(t_data *data, t_box *box, int flag)
{
	if (!box->next && !box->prev)
	{
		close(data->info->stdin);
		close(data->info->stdout);
	}
	if (flag == 2)
		error_exit(box->arguments[1]);
	free_env(data->env);
	free(data->cwd);
	free(data->input);
	ft_free();
	if (flag)
		exit(flag);
	exit(data->exit_status);
}

int	ft_exit(t_box *box, t_data *data)
{
	int	*d;
	int	val;

	if (!box->arguments[1])
		free_exit(data, box, 0);
	d = check_numeric(box->arguments[1]);
	if (d[0] == -1 || d[0] > 19 || !*box->arguments[1])
		free_exit(data, box, 2);
	if (box->arguments[1] && box->arguments[2])
		return (ft_putstr_fd(TMA, 2), 1);
	val = check_valid(d, box->arguments[1]);
	free_exit(data, box, val);
	return (0);
}

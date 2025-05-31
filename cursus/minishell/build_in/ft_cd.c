/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:27:38 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:26 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd(t_data *all_data, t_box *data)
{
	char	*pwd;

	if (!data->arguments[1])
		return (ft_putstr_fd(CWWOAROAP, 2), 2);
	else if (data->arguments[2])
		return (ft_putstr_fd(MCTMA, 2), 2);
	if (chdir(data->arguments[1]) != 0)
		return (perror(data->arguments[1]), 1);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror(CWDNW);
		return (1);
	}
	add_value(all_data, "OLDPWD=", get_val("PWD", all_data->env));
	add_value(all_data, "PWD=", pwd);
	free(all_data->cwd);
	all_data->cwd = ft_strdup(pwd, malloc);
	free(pwd);
	return (0);
}

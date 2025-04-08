/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:03:16 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/21 13:27:48 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_var(int val)
{
	static int	r;

	if (val == -1)
		return (r);
	r = val;
	return (r);
}

void	get_promot(t_data *data)
{
	while (1)
	{
		data->c_flag = 0;
		data->input = readline("MINISHELL-> ");
		if (!data->input)
		{
			rl_clear_history();
			free_env(data->env);
			free(data->cwd);
			exit((printf("exit\n"), ft_free(), data->exit_status));
		}
		if (data->input[0])
		{
			if (check_unclose_quotes(data->input))
			{
				ft_putstr_fd(AEITS, 2);
				data->exit_status = 2;
			}
			else
				data->exit_status = ft_tokenizer(data);
			add_history(data->input);
		}
		free(data->input);
		ft_free();
	}
}

int	main(int ac, char **av, char **ev)
{
	t_data	data;
	t_card	info;

	(void)av;
	(void)ac;
	get_signals();
	data.info = &info;
	data.env = cp_env(ev);
	data.cwd = getcwd(NULL, 0);
	data.exit_status = 0;
	data_giver(&data);
	get_promot(&data);
	return (0);
}

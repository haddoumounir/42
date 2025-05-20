/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:50:26 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/19 17:53:24 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*generete_name(void)
{
	char	*name;
	int		fd;
	char	*buffer;
	int		i;
	int		buffer_size;

	buffer = RNDBUFF;
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (NULL);
	name = (char *)ft_malloc(21);
	if (read(fd, name, 20) == -1)
		return (close(fd), NULL);
	name[20] = '\0';
	i = 0;
	buffer_size = ft_strlen(buffer);
	while (i != 20)
	{
		name[i] = buffer[name[i] % buffer_size];
		i++;
	}
	close(fd);
	return (name);
}

void	handle_ctl_d(t_data *data)
{
	rl_clear_history();
	free_env(data->env);
	free(data->cwd);
	free(data->input);
	(ft_free(), exit(0));
}

char	*here_doc_expand(char *line, t_data *data)
{
	char	*pre;
	char	*sub;
	char	*next;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		j = 0;
		if (line[i] == '$')
		{
			pre = ft_substr(line, 0, ++i - 1);
			while (line[i + j] && (line[i + j] == '_' || ft_isalnum(line[i
							+ j])))
				j++;
			next = ft_substr(line, i + j, ft_strlen(line) - i - j);
			sub = get_val(ft_substr(line, i, j), data->env);
			line = ft_strjoin(ft_strjoin(pre, sub), (i = 0, next));
			continue ;
		}
		i++;
	}
	return (line);
}

void	child_heredoc(t_data *data, char *name, char *del, int expand)
{
	char	*line;
	char	*tmp;
	
	rl_clear_history();
	data->fd_h_w = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (data->fd_h_w == -1)
		handle_ctl_d((data));
	signal_heredoc();
	while (1)
	{
		line = readline("> ");
		if (!line)
			handle_ctl_d((close(data->fd_h_w), data));
		tmp = ft_strdup(line, ft_malloc);
		free(line);
		if (!ft_strcmp(tmp, del))
			break ;
		if (expand == VAR || expand == ARGUMENT)
			tmp = here_doc_expand(tmp, data);
		write(data->fd_h_w, ft_strjoin(tmp, "\n"), ft_strlen(tmp) + 1);
	}
	handle_ctl_d((close(data->fd_h_w), data));
}

char	*here_doc(t_data *data, int expand, char *del)
{
	char	*name;
	int		pid;

	name = ft_strjoin("/tmp/.here_doc", generete_name());
	pid = fork();
	g_var(1);
	if (pid == 0)
		child_heredoc(data, name, del, expand);
	waitpid(pid, &data->exit_status, 0);
	if (WIFEXITED(data->exit_status))
		data->exit_status = WEXITSTATUS(data->exit_status);
	else
		data->exit_status = WTERMSIG(data->exit_status);
	if (data->exit_status == 130)
		data->c_flag = 1;
	g_var(0);
	return (name);
}

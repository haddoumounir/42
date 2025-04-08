/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:03:23 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/22 20:54:57 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

# define AEITS "an error in the syntax \n"
# define MCTA "Minishell can't take arguments\n"
# define NAC ": numeric argument required\n"
# define EXP1 "minishell: export: `"
# define EXP2 "': not a valid identifier\n"
# define TMA "minishell: exit: too many arguments\n"
# define CORRECT 1
# define INCORRECT 0
# define GETCWD "pwd: error retrieving current directory:\
 getcwd: cannot access parent directories"
# define CWWOAROAP "cd work with only a relative or absolute path\n"
# define MCTMA "minishell: cd: too many arguments\n"
# define DEBUG "DEBUG"
# define NSFOD ": No such file or directory\n"
# define IAS ": Is a directory\n"
# define CNF ": command not found\n"
# define RNDBUFF "ygapownvsywerosdfpouewf"
# define CAM "can't allocate memory\n"
# define MSENUT "minishell: syntax error near unexpected token "
# define MNSFOD "minishell: : No such file or directory\n"
# define CWDNW "cd: error retrieving current directory:\
 getcwd: cannot access parent directories"

typedef enum e_token_types
{
	S_QUOTED = 1,
	D_QUOTED,
	ARGUMENT,
	ROO,
	RIO,
	HEREDOC,
	APPEND,
	PIPE,
	VAR = 10
}							t_token_types;

typedef struct s_redirection
{
	int						type;
	char					*file;
	int						is_q;
	struct s_redirection	*next;
}							t_redirection;

typedef struct s_box
{
	int						type;
	char					**arguments;
	int						**types;
	t_redirection			*redirection_op;
	int						here_doc;
	struct s_box			*prev;
	struct s_box			*next;
}							t_box;
typedef struct s_card
{
	int						infile;
	int						outfile;
	int						pipe[2];
	int						pipe_i;
	pid_t					pid;
	int						status;
	char					*path;
	int						stdin;
	int						stdout;
	int						current_pipe;
	int						red_flag;
}							t_card;

typedef struct s_token
{
	char					*part;
	t_token_types			type;
	struct s_token			*pre;
	struct s_token			*next;
	int						join;
	int						linked;

}							t_token;

typedef struct s_env
{
	char					*var;
	char					*val;
	struct s_env			*next;
}							t_env;

typedef struct s_data
{
	char					*input;
	size_t					i;
	char					*part_temp;
	int						type_p_temp;
	int						tempjoin;
	t_token					*head;
	char					**del;
	char					**env;
	int						exit_status;
	t_box					*box;
	char					**cp;
	char					*cwd;
	int						heredoc_fd;
	t_card					*info;
	int						c_flag;
	int						fd_h_r;
	int						fd_h_w;
	int						is_here;
}							t_data;

typedef struct s_mem_block
{
	void					*ptr;
	int						type;
	struct s_mem_block		*next;
}							t_mem_block;

typedef struct s_dollar_d_qoute
{
	size_t					ip;
	size_t					j;
	char					*name;
	int						flag;
	char					*pre;
	int						isnull;
	char					*next;
}							t_dollar_d_qoute;

t_data						*data_giver(t_data *data);
int							g_var(int val);
int							ft_isspace(int c);
int							ft_is_c(char c);
int							ft_is_c_exeption(char c, char exp);
char						**ft_split(char const *s, char c);
char						*ft_strchr(const char *s, int c);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int							execution(t_data *data);
int							count_cmd(t_box *data);
void						*ft_memset(void *s, int c, size_t n);
char						*find_path(t_data *data, char **cmd, char **env);
void						handle_redir(t_data *data, t_box *box,
								t_card *info);
void						set_in_out(t_box *cmd, t_card *info);
void						open_file(t_data *data, t_redirection *redir,
								t_card *info);
void						print_error(char *str, t_data *data, int flag);
char						*ft_itoa(int n);
void						ft_free(void);
void						*ft_calloc(size_t nmemb, size_t size);
void						*ft_memcpy(void *dest, const void *src, size_t n);
char						delimiters(char c);
char						**cp_env(char **env);
int							ft_strcmp(const char *s1, const char *s2);
void						add_node(t_data *data, char *var);
char						*ft_strdup(const char *s,
								void *(alloc)(size_t size));
int							ft_isdigit(int c);
void						ft_sub_str_with_del(t_data *data, char c);
void						ft_token_qoute(t_data *data);
void						ft_token_dollar(t_data *data);
void						ft_token_args(t_data *data);
char						*extract_var(char *env);
int							check_builtin(char **cmd);
int							execute_builtin(t_data *data, t_box *cmd);
int							ft_pwd(t_data *data);
size_t						ft_strlen(const char *str);
void						ft_putstr_fd(char *s, int fd);
int							ft_exit(t_box *box, t_data *data);
long long					ft_atoi(char *npt);
int							ft_echo(t_box *cmd);
int							ft_export(t_data *data, t_box *cmd);
int							ft_strchr_pos(const char *s, int c, bool varb);
int							ft_unset(t_data *data, t_box *cmd);
int							ft_env(char **env);
int							ft_cd(t_data *all_data, t_box *data);
void						ft_add_token(t_data *data);
t_token						*ft_new_token(char *part, int type, int tempjoin);
void						ft_token_roo_rio_pipe(t_data *data);
void						ft_token_app_ro_her_ro(t_data *data);
int							ft_tokenizer(t_data *data);
char						*get_val(char *var, char **env);
int							check_unclose_quotes(char *str);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
int							is_white_space(int c);
int							ft_is_qoute(char c);
int							ft_is_roo_rio(char c);
int							ft_is_alpha(int c);
int							ft_isalnum(int c);
int							ft_is_not_red_pipe(char c);
void						*ft_malloc(size_t size);
int							ft_grammar_checker(t_data *data);
char						*ft_strjoin(const char *s1, const char *s2);
void						get_promot(t_data *data);
void						free_env(char **env);
void						get_signals(void);
int							herdoc_checker(t_data *data);
char						*here_doc(t_data *data, int expand, char *del);
char						*generete_name(void);
int							check_cmd(char **cmd);
int							check_full_arg(char *str);
void						add_value(t_data *data, char *var, char *value);
int							calc_args(t_data *data);
int							calc_r(t_token *temp, int type);
t_box						*create_box(size_t size);
int							calc_args_from_token(t_token *temp);
t_box						*set_back_cmd(t_data *data);
void						ft_tree_reduction(t_box **thead, t_token **temp);
void						ft_tree_pipe(t_box **thead, t_token **temp, int *i);
void						ft_tree_arg(t_box **thead, t_token **temp, int *i);
int							ft_join(t_data *data);
int							error_grammer(char *str);
int							ft_pipe(t_token *temp);
int							ft_rederect(t_token *temp);
int							ft_tree(t_data *data);
void						ft_token_var(t_data *data);
void						herdoc_del(t_data *data, int flag);
int							check_value(char *var);
void						sig_handler(int sig);
void						signal_heredoc(void);
int							handle_redir_builtin(t_data *data, t_box *box,
								t_card *info);
void						print_error_b(char *str, t_data *data, int status);
void						set_fds(t_data *data);
void						ft_dollar_at_d_qoute(t_data *data);
void						ft_handle_dollar_at_d_qoute(t_data *data,
								size_t *i);
int							check_last_herdoc(t_data *data);
void						ft_d_qoute_non_valid(t_data *data, t_dollar_d_qoute *dq);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:40:53 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 11:23:49 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# define NCNFA "Not correct number of argments \n"
# define NVA "Invalid argments\n"
# define PHHTAF " has taken a fork"
# define PHIE "is eating"
# define PHIS "is sleeping"
# define PHIT "is thinking"
# define PHD "died"

typedef struct s_info	t_info;

typedef struct s_philo
{
	pthread_t			pth;
	int					nbr;
	size_t				mnbr;
	pthread_mutex_t		fork;
	long				last_time_eat;
	t_info				*data;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

typedef struct s_info
{
	int					ac;
	char				**av;
	int					nop;
	int					ttd;
	int					tte;
	int					tts;
	int					notepme;
	long				start_time;
	pthread_mutex_t		mtte;
	pthread_mutex_t		mprint;
	pthread_mutex_t		mdeath;
	pthread_mutex_t		mnext;
	t_philo				*philo;
	pthread_t			pthrespo;
	int					is_death;
}						t_info;

void					destroy_mutexes(t_info *data);
void					ft_clean(t_info *data, int philo_nbr);
void					ft_join(t_info *data);
int						ft_create(t_info *data);
void					mutex_init(t_info *data);
void					ft_clear_part(t_philo *head, int val);
int						valid_alloc(size_t size, t_philo **var);
int						initialize_philos(t_info *data);
int						checker(t_info *data);
int						ft_sleep(t_philo *philo);
int						ft_think(t_philo *philo);
void					is_odd(t_philo *philo);
void					is_even(t_philo *philo);
int						ft_eat(t_philo *philo);
int						check_philo_death(t_philo *philo);
int						check_meals(t_info *data);
void					*respo(void *var);
void					*routine(void *var);
int						input_checker(char *str);
int						ft_atoi(char *nptr);
int						checker_life(t_info *data);
void					printer(char *str, t_philo *philo);
long					time_in_ms(void);
int						is_death(t_philo *philo);
int						ft_strlen(char *str);
#endif
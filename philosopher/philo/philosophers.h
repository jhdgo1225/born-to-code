/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:01:32 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/22 12:59:04 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nums;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times;
	int				death_sign;
	int				waiting_sign;
	long long		start_time;
	pthread_mutex_t	monitoring_lock;
	pthread_mutex_t	*forks_lock;
	int				*forks;
}				t_data;

typedef struct s_philo
{
	int			idx;
	int			left;
	int			right;
	int			meal_cnt;
	long long	eat_time;
	pthread_t	thread;
	t_data		*pub_data;
}				t_philo;

int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_sleep(long long time, t_data *data);
long long	get_cur_time(void);
int			monitor_philo(t_data *data);
void		print_msg(t_philo *philo, t_data *data, char *msg);
int			select_first(t_philo *philo);
int			select_second(t_philo *philo);
t_philo		*init_philos(t_data *data);
int			init_datas(t_data *philo, t_philo *philos);
void		simulate_philo(t_data *data, t_philo *philos);
void		exec_exit_processing(t_philo *philos, t_data *data, int end);
void		clear_fork_locks(t_data *data, int end);
void		clear_threads(t_philo *philos, int end);
void		free_in_philos(t_philo *philos, t_data *data);
int			get_forks(t_philo *philo, t_data *data);
int			get_a_meal(t_philo *philo, t_data *data);
int			get_a_sleep(t_philo *philo, t_data *data);

#endif

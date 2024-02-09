/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:13:31 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 19:33:37 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_data *data, t_philo *philos)
{
	int	i;

	data->forks = (int *)malloc(sizeof(int) * data->nums);
	if (data->forks == NULL)
	{
		free(philos);
		return (1);
	}
	data->forks_lock = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nums);
	if (data->forks_lock == NULL)
	{
		free(data->forks);
		free(philos);
		return (1);
	}
	i = -1;
	while (++i < data->nums)
		data->forks[i] = 0;
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
	{
		if (pthread_mutex_init(&(data->forks_lock[i]), NULL))
		{
			clear_fork_locks(data, i);
			return (1);
		}
	}
	if (pthread_mutex_init(&(data->monitoring_lock), NULL))
	{
		clear_fork_locks(data, data->nums);
		return (1);
	}
	return (0);
}

int	init_datas(t_data *data, t_philo *philos)
{
	if (init_forks(data, philos))
	{
		printf("Error: Memory allocation is failed!\n");
		return (1);
	}
	if (init_mutexes(data) != 0)
	{
		printf("Error: Mutex init error!\n");
		free_in_philos(philos, data);
		return (1);
	}
	return (0);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * (data->nums));
	if (philos == NULL)
	{
		printf("Error: Memory allocation is failed!\n");
		return (NULL);
	}
	i = -1;
	while (++i < data->nums)
	{
		philos[i].idx = i + 1;
		philos[i].left = i;
		philos[i].right = (i + 1) % data->nums;
		philos[i].meal_cnt = 0;
		philos[i].pub_data = data;
	}
	return (philos);
}

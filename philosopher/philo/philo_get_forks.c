/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:43:25 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 19:33:34 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_a_fork(t_philo *philo, t_data *data, int grab)
{
	if (monitor_philo(data))
		return (1);
	while (get_cur_time() - philo->eat_time < data->time_to_die)
	{
		pthread_mutex_lock(&(data->forks_lock[grab]));
		if (data->forks[grab] == 0)
		{
			data->forks[grab] = 1;
			pthread_mutex_unlock(&(data->forks_lock[grab]));
			print_msg(philo, data, "has taken a fork");
			return (0);
		}
		pthread_mutex_unlock(&(data->forks_lock[grab]));
		usleep(200);
	}
	return (1);
}

int	get_forks(t_philo *philo, t_data *data)
{
	int	first;
	int	second;

	first = select_first(philo);
	second = select_second(philo);
	if (monitor_philo(data))
		return (1);
	if (!get_a_fork(philo, data, first) && !get_a_fork(philo, data, second))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_a_meal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:32 by devpark           #+#    #+#             */
/*   Updated: 2023/11/22 15:24:29 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	put_forks(t_philo *philo, t_data *data)
{
	int	first;
	int	second;

	first = select_first(philo);
	second = select_second(philo);
	if (data->forks[first] == 1)
		data->forks[first] = 0;
	if (data->forks[second] == 1)
		data->forks[second] = 0;
	pthread_mutex_unlock(&(data->forks_lock[first]));
	pthread_mutex_unlock(&(data->forks_lock[second]));
}

void	not_get_a_meal(t_philo *philo, t_data *data)
{
	while (get_cur_time() - philo->eat_time < data->time_to_die)
		;
	put_forks(philo, data);
}

int	get_a_meal(t_philo *philo, t_data *data)
{
	long long	past_time;

	if (monitor_philo(data))
		return (1);
	pthread_mutex_lock(&(data->forks_lock[philo->right]));
	pthread_mutex_lock(&(data->forks_lock[philo->left]));
	if (data->time_to_eat == 0)
	{
		not_get_a_meal(philo, data);
		return (1);
	}
	print_msg(philo, data, "is eating");
	past_time = get_cur_time() - philo->eat_time;
	while (get_cur_time() - philo->eat_time < past_time + data->time_to_eat)
	{
		if (get_cur_time() - philo->eat_time >= data->time_to_die)
		{
			put_forks(philo, data);
			return (1);
		}
		usleep(200);
	}
	philo->eat_time = get_cur_time();
	put_forks(philo, data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:52:12 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 19:33:39 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_routine(t_philo *philo, t_data *data)
{
	philo->eat_time = get_cur_time();
	if (!(philo->idx % 2))
		ft_sleep((data->time_to_eat / 2), data);
	while (1)
	{
		if (get_forks(philo, data))
			break ;
		if (get_a_meal(philo, data))
			break ;
		philo->meal_cnt++;
		if (philo->meal_cnt == data->num_of_times && data->num_of_times != -1)
			break ;
		if (get_a_sleep(philo, data))
			break ;
	}
}

int	wait_routine(t_data *data)
{
	pthread_mutex_lock(&(data->monitoring_lock));
	if (data->waiting_sign)
	{
		pthread_mutex_unlock(&(data->monitoring_lock));
		return (1);
	}
	pthread_mutex_unlock(&(data->monitoring_lock));
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (wait_routine(philo->pub_data))
		;
	start_routine(philo, philo->pub_data);
	if (philo->pub_data->num_of_times == -1
		|| philo->meal_cnt != philo->pub_data->num_of_times)
		print_msg(philo, philo->pub_data, "died");
	return (NULL);
}

void	simulate_philo(t_data *data, t_philo *phs)
{
	int	i;

	i = -1;
	data->waiting_sign = 1;
	data->death_sign = 0;
	while (++i < data->nums)
	{
		if (pthread_create(&(phs[i].thread), 0, routine, (void *)&phs[i]))
		{
			exec_exit_processing(phs, data, data->nums);
			return ;
		}
		if (i + 1 == data->nums)
		{
			pthread_mutex_lock(&(data->monitoring_lock));
			data->waiting_sign = 0;
			data->start_time = get_cur_time();
			pthread_mutex_unlock(&(data->monitoring_lock));
		}
	}
	exec_exit_processing(phs, data, data->nums);
}

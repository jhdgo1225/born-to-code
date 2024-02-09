/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:35:03 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 18:41:44 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_fork_locks(t_data *data, int end)
{
	int	i;

	i = 0;
	while (i < end)
		pthread_mutex_destroy(&(data->forks_lock[i++]));
}

void	clear_threads(t_philo *philos, int end)
{
	int	i;

	i = 0;
	while (i < end)
		pthread_join(philos[i++].thread, NULL);
}

void	free_in_philos(t_philo *philos, t_data *data)
{
	free(data->forks);
	free(data->forks_lock);
	free(philos);
}

void	exec_exit_processing(t_philo *philos, t_data *data, int end)
{
	clear_threads(philos, end);
	clear_fork_locks(data, data->nums);
	pthread_mutex_destroy(&(data->monitoring_lock));
	free_in_philos(philos, data);
}

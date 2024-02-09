/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_a_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:11 by devpark           #+#    #+#             */
/*   Updated: 2023/11/22 14:19:51 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_a_sleep(t_philo *philo, t_data *data)
{
	if (monitor_philo(data))
		return (1);
	if (data->time_to_sleep > 0)
		print_msg(philo, data, "is sleeping");
	while (get_cur_time() - philo->eat_time < data->time_to_sleep)
	{
		if (get_cur_time() - philo->eat_time >= data->time_to_die)
			return (1);
		ft_sleep(1, data);
	}
	print_msg(philo, data, "is thinking");
	if (data->nums % 2 || data->time_to_sleep == 0)
	{
		if (data->time_to_eat > data->time_to_sleep)
			ft_sleep(data->time_to_eat - data->time_to_sleep, data);
	}
	if (data->nums % 2)
		usleep(300);
	return (0);
}

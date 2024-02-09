/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:30:56 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:54 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	select_first(t_philo *philo)
{
	if (philo->idx % 2)
		return (philo->left);
	return (philo->right);
}

int	select_second(t_philo *philo)
{
	if (philo->idx % 2)
		return (philo->right);
	return (philo->left);
}

void	ft_sleep(long long time, t_data *data)
{
	long long	start;

	start = get_cur_time();
	while (get_cur_time() - start < time)
		usleep((data->nums / 50 + 1) * 50);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:41:59 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 19:33:40 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "philosophers.h"

int	monitor_philo(t_data *data)
{
	pthread_mutex_lock(&(data->monitoring_lock));
	if (data->death_sign == 1)
	{
		pthread_mutex_unlock(&(data->monitoring_lock));
		return (1);
	}
	pthread_mutex_unlock(&(data->monitoring_lock));
	return (0);
}

long long	get_cur_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(t_philo *philo, t_data *data, char *msg)
{
	pthread_mutex_lock(&(data->monitoring_lock));
	if (data->death_sign == 0)
	{
		printf("%lld %d %s\n", \
			get_cur_time() - data->start_time, philo->idx, msg);
		if (ft_strncmp(msg, "died", 5) == 0)
			data->death_sign = 1;
	}
	pthread_mutex_unlock(&(data->monitoring_lock));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned long	ret;
	unsigned long	temp;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	i += (str[i] == '+' || str[i] == '-');
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = ret * 10 + (str[i] - '0');
		if (temp > (unsigned long) INT_MAX || ret > temp)
			return (-1 + (sign < 0));
		ret = temp;
		i++;
	}
	return (ret * sign);
}

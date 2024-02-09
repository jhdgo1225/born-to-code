/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:12:41 by jonghopa          #+#    #+#             */
/*   Updated: 2023/11/21 19:31:16 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != 0)
		{
			if ((argv[i][0] == '+' || argv[i][0] == '-')
				&& (argv[i][1] >= '0' && argv[i][1] <= '9'))
				continue ;
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') == 0)
				return (1);
		}
	}
	return (0);
}

int	check_pos(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == 0)
			return (1);
		if (ft_atoi(argv[i]) < 0)
			return (1);
	}
	return (0);
}

int	processing_args(int argc, char **argv, t_data *data)
{
	if (check_digit(argc, argv) || check_pos(argc, argv))
	{
		printf("Error: All arguments is positive integer!\n");
		return (1);
	}
	data->nums = ft_atoi(argv[1]);
	if (data->nums == 0)
	{
		printf("No one is around a table!\n");
		return (1);
	}
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		data->num_of_times = -1;
	else
		data->num_of_times = ft_atoi(argv[5]);
	if (data->num_of_times == 0)
	{
		printf("No one eats a meal!\n");
		return (1);
	}
	return (0);
}

int	check_argc(int argc)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("Usage: ./philo ");
		printf("[number_of_philosophers] ");
		printf("[time_to_die] ");
		printf("[time_to_eat] ");
		printf("[time_to_sleep] ");
		printf("[number_of_times_each_philosophers_must_eat(Option)]\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (check_argc(argc) || processing_args(argc, argv, &data))
		return (1);
	philos = init_philos(&data);
	if (philos == NULL)
		return (1);
	if (init_datas(&data, philos))
		return (1);
	simulate_philo(&data, philos);
	return (0);
}

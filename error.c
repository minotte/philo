/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:01:16 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/05 18:27:22 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	error_not_number(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_philo_arg(int argc, char **argv, t_data_init *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->philo_must_eat_time = -1;
	if (argc == 6)
	{
		data->philo_must_eat_time = ft_atoi(argv[5]);
		if (data->philo_must_eat_time < 1
			|| data->philo_must_eat_time > 200)
		{
			ft_putendl_fd("can you put a positive value more than 0", 2);
			return (0);
		}
	}
	if (data->nbr_philos < 1 || data->time_die < 1 || data->time_eat < 1
		|| data->time_sleep < 1 || data->nbr_philos > 200
		|| data->time_die > 2147483647 || data->time_eat > 2147483647
		|| data->time_sleep > 2147483647)
	{
		ft_putendl_fd("can you put a positive value up to 0"
			" and less than 200", 2);
		return (0);
	}
	return (1);
}

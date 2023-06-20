/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:01:16 by nminotte          #+#    #+#             */
/*   Updated: 2023/06/09 15:59:22 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	error_not_number(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_philo_arg(int argc, char **argv, t_data_init *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->must_eat_time = -1;
	if (argc == 6)
	{
		data->must_eat_time = ft_atoi(argv[5]);
		if (data->must_eat_time < 1
			|| data->must_eat_time > 2147483647)
		{
			ft_putendl_fd("The last arg need to be between 0 and max int.", 2);
			return (0);
		}
	}
	if (data->nbr_philos < 1 || data->time_die < 1 || data->time_eat < 1
		|| data->time_sleep < 1 || data->nbr_philos > 250
		|| data->time_die > 2147483647 || data->time_eat > 2147483647
		|| data->time_sleep > 2147483647)
	{
		ft_putendl_fd("can you put a positive value up to 0 and less"
			" than 2147483647 and less than 250 for the 1st arg\n", 2);
		return (0);
	}
	return (1);
}

int	parsing(int argc, char **argv, t_data_init *data)
{
	if (argc < 5 || argc > 6)
	{
		print_arg_error();
		return (1);
	}
	if (error_not_number(argv) != 0)
	{
		printf("write all your argument in decimal up than 0\n");
		return (1);
	}
	if (ft_philo_arg(argc, argv, data) == 0)
		return (1);
	return (0);
}

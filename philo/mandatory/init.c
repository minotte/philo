/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:37:37 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/23 20:32:59 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(t_data_init *data)
{
	int	ret;

	ret = 0;
	if (pthread_mutex_init(&data->dead, NULL) != 0)
	{
		printf("mutex failed\n");
		return (1);
	}
	data->is_dead = 0;
	if (pthread_mutex_init(&data->write, NULL) != 0)
	{
		printf("mutex failed\n");
		return (1);
	}
	data->finish = 0;
	pthread_mutex_init(&data->all_are_full, NULL);
	data->nbr_meal = 0;
	data->mu_fork = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	ret = wrong_malloc(data->mu_fork);
	data->rout_phil = malloc(sizeof(pthread_t) * (data->nbr_philos));
	ret = wrong_malloc(data->rout_phil);
	return (ret);
}

int	init_phi(t_philo *phi, t_data_init *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&data->mu_fork[i], NULL) != 0)
		{
			printf("mutex failed\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		phi[i].index = i;
		phi[i].dinner_nbr = 0;
		phi[i].data = data;
		phi[i].last_eat = 0;
		pthread_mutex_init(&phi[i].l_eat, NULL);
		i++;
	}
	return (0);
}

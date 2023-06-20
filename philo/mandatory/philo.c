/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:00:18 by nminotte          #+#    #+#             */
/*   Updated: 2023/06/06 10:40:34 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	phi_full(t_data_init *data)
{
	pthread_mutex_lock(&data->all_are_full);
	if (data->nbr_meal == data->nbr_philos)
	{
		pthread_mutex_unlock(&data->all_are_full);
		return (1);
	}
	pthread_mutex_unlock(&data->all_are_full);
	return (0);
}

void	is_dead(t_philo *phi, t_data_init *data, int i, long int time_n)
{
	pthread_mutex_unlock(&phi[i].l_eat);
	pthread_mutex_lock(&data->dead);
	data->is_dead = 1;
	pthread_mutex_unlock(&data->dead);
	pthread_mutex_lock(&data->write);
	printf("%s%ld	%d is dead%s\n", R, time_n, phi[i].index + 1, CE);
	pthread_mutex_unlock(&data->write);
}

void	all_is_alive(t_philo *phi, t_data_init *data)
{
	long int	time_n;
	int			i;

	while (1)
	{
		i = 0;
		while (i < data->nbr_philos)
		{
			if (phi_full(data) == 1)
				return ;
			time_n = what_time(data->time_start);
			pthread_mutex_lock(&phi[i].l_eat);
			if (time_n - phi[i].last_eat > data->time_die)
			{
				is_dead(phi, data, i, time_n);
				return ;
			}
			pthread_mutex_unlock(&phi[i].l_eat);
			i++;
		}
	}
}

void	ft_philo_one(t_data_init *data, t_philo *phi)
{
	int	err;

	err = pthread_create(&data->rout_phil[0], NULL, &r_philo, &phi[0]);
	if (err != 0)
	{
		printf("error on thread\n");
		return ;
	}
	all_is_alive(phi, data);
	if (pthread_join(data->rout_phil[0], NULL) != 0)
	{
		printf("error on join thread\n");
		return ;
	}
}

void	ft_philo(t_data_init *d, t_philo *phi)
{
	int	i;

	i = 0;
	while (i < d->nbr_philos)
	{
		if (pthread_create(&d->rout_phil[i], NULL, &r_philo, &phi[i]) != 0)
		{
			printf("error on creating thread %d\n", i);
			return ;
		}
		i++;
	}
	all_is_alive(phi, d);
	i = 0;
	while (i < d->nbr_philos)
	{
		if (pthread_join(d->rout_phil[i], NULL) != 0)
		{
			printf("error on join thread\n");
			return ;
		}
		i++;
	}
}

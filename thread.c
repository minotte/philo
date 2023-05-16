/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:10:29 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 18:36:12 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <pthread.h>

void	*all_is_alive(void *arg)
{
	t_data_init	*data;
	long int	time_n;
	int			i;

	data = arg;
	usleep(1500);
	while (data->is_dead == 0)
	{
		i = 0;
		time_n = what_time(data->time_start);
		pthread_mutex_lock(&data->dead);
		while (i < data->nbr_philos)
		{
		// time_n = what_time(data->time_start);
			// printf("philo numero : %d\n", data->phi[i].index);
			// printf("%d time_last eat : %ld\n", data->phi[i].index, data->phi->last_eat);printf("irrere time_start  : %ld\n", data->time_start );

			time_n = what_time(data->time_start);
			// printf("time_n : %ld\n", time_n );

			// if (data->is_dead == 1)
			// {
				// printf("-----------test------------------------ \n");
				// break ;
			// }
			// printf("what time  : %ld\n", time_n - data->phi[i].last_eat );
			if (data->time_die < (time_n - data->phi[i].last_eat))
			{	
				pthread_mutex_lock(&data->write);
				printf("%s %ld	%d is dead%s \n", RED, time_n, data->phi->index + 1, CE);
				// ft_msg_philo(time_n, data->phi, DEAD);
				data->is_dead = 1;
				// pthread_mutex_unlock(&data->write);
				// pthread_mutex_unlock(&data->dead);
				// printf("is_dead : %d \n", data->phi[i].is_dead);
			break ;
			}

			i++;
			if (data->is_dead == 1)
			{
				// printf("-----------test------------------------ \n");
				// pthread_mutex_unlock(&data->dead);

				return (NULL);
			}
		}

	 pthread_mutex_unlock(&data->dead);
// printf("-----------test------------------------ \n");
	}
	 pthread_mutex_unlock(&data->dead);
	 // printf("fin \n");
}

void	*rout_phi_one(void *arg)
{
	t_philo	*phi;

	phi = arg;
	ft_msg_philo(0, phi, FORK);
	all_is_alive(phi);
}

void	*routine_philo(void *arg)
{
	t_philo	*phi;
	int		i;

	phi = arg;
	i = phi->index;
	if (phi->index % 2 != 0)
	{
		ft_msg_philo(0, phi, THINK);
		usleep(500);
	}
	// phi->is_dead == is_dead(phi);
	while (phi->data->is_dead == 0 && (phi->data->must_eat_time < 0
			|| phi->dinner_nbr < phi->data->must_eat_time))
	{
		pthread_mutex_lock(&phi->data->dead);
		if (phi->data->is_dead == 0)
		{
			pthread_mutex_unlock(&phi->data->dead);
			eating(phi);
			sleeping(phi);	
			// ft_msg_philo(phi->te, phi, THINK);

			// phi->is_dead == is_dead(phi);
		}
		else
		{
			pthread_mutex_unlock(&phi->data->dead);
			return (NULL);
		}
	}
	return (NULL);
}

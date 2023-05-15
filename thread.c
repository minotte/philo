/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:10:29 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/15 19:39:25 by nminotte         ###   ########.fr       */
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
	printf("TEST f: %d\n", data->time_die);
	printf("re time_start  : %ld\n", data->time_start );
	i = 0;
	while (1)
	{
		// time_n = what_time(data->time_start);
		// printf("time_t : %ld\n", ft_time()  );
		// time_n = ft_time() - data->time_start;
		printf("irrere time_start  : %ld\n", data->time_start );
		// printf("time_n : %ld\n", time_n );
		// printf("%d time_last eat : %ld\n", data->phi->index, data->phi->last_eat);
		/*pthread_mutex_lock(&data->dead);
		if (data->phi->is_dead == 1)
		{
			break;
		}
		if ((data->time_die < time_n - data->phi->last_eat))
		{	
			pthread_mutex_lock(&data->write);
			ft_msg_philo(time_n, data->phi, DEAD);
			data->phi->is_dead = 1;
			pthread_mutex_unlock(&data->write);
			pthread_mutex_unlock(&data->dead);
		}*/
		break;
	}
	// pthread_mutex_unlock(&data->dead);
}

void	*rout_phi_one(void *arg)
{
	t_philo	*phi;

	phi = arg;
	ft_msg_philo(0, phi, FORK);
	// is_dead(phi);
}

void	*routine_philo(void *arg)
{
	t_philo	*phi;
	int		i;

	phi = arg;
	i = phi->index;
	ft_msg_philo(0, phi, THINK);
	if (phi->index % 2 != 0)
		usleep(500);
	// phi->is_dead == is_dead(phi);
	while (phi->is_dead == 0 && (phi->data->must_eat_time < 0
			|| phi->dinner_nbr < phi->data->must_eat_time))
	{
		// pthread_mutex_lock(&phi->data->dead);
		if (phi->is_dead == 0)
		{
			// pthread_mutex_unlock(&phi->data->dead);
			eating(phi);
			sleeping(phi);
			// phi->is_dead == is_dead(phi);
		}
		else
		{
			pthread_mutex_unlock(&phi->data->dead);
			return (NULL);
		}
	}
}

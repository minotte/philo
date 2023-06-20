/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:49:59 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/23 20:22:38 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *phi)
{
	ft_msg_philo(phi, SLEEP);
	time_to_spend(phi->data->time_sleep, phi->data);
	ft_msg_philo(phi, THINK);
}

int	rout_philo(t_philo *phi)
{
	pthread_mutex_lock(&phi->data->dead);
	if (phi->data->is_dead == 1)
	{
		pthread_mutex_unlock(&phi->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&phi->data->dead);
	eat(phi);
	pthread_mutex_lock(&phi->data->all_are_full);
	if (phi->data->nbr_meal == phi->data->nbr_philos)
	{
		pthread_mutex_unlock(&phi->data->all_are_full);
		return (1);
	}
	pthread_mutex_unlock(&phi->data->all_are_full);
	sleeping(phi);
	return (0);
}

void	*r_philo(void *arg)
{
	t_philo	*phi;
	int		ret;

	phi = arg;
	if (phi->data->nbr_philos == 1)
	{
		pthread_mutex_lock(&phi->data->mu_fork[0]);
		ft_msg_philo(phi, FORK);
		pthread_mutex_unlock(&phi->data->mu_fork[0]);
		return (NULL);
	}
	if (phi->index % 2 == 0)
	{
		ft_msg_philo(phi, THINK);
		if (phi->data->time_die < phi->data->time_eat)
			usleep((phi->data->time_die * 100));
		else
			usleep((phi->data->time_eat * 100));
	}
	ret = 0;
	while (ret == 0)
	{
		ret = rout_philo(phi);
	}
	return (NULL);
}

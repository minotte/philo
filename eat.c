/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:39:21 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 16:59:21 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/philo.h"


// probleme temps

void	eating(t_philo *phi)
{
	int	i;

	i = phi->index;
	// printf("time_start  : %ld\n", phi->data->time_start );
	if (phi->data->is_dead == 0)
	{
		pthread_mutex_lock(&phi->data->mu_fork[i]);
		if (i == (phi->data->nbr_philos - 1))
			pthread_mutex_lock(&phi->data->mu_fork[0]);
		else
			pthread_mutex_lock(&phi->data->mu_fork[i + 1]);
		if (phi->index % 2 != 0)
			phi->te = what_time(phi->data->time_start);
		ft_msg_philo(phi->te, phi, FORK);
		ft_msg_philo(phi->te, phi, FORK);
		// printf("%d last_eat  ouioui: %ld\n", phi->index, phi->last_eat);
		phi->dinner_nbr++;
		ft_msg_philo(phi->te, phi, EAT);
		phi->te += time_to_spend(phi->data->time_eat, phi);
		phi->last_eat = phi->te;
		// ft_msg_philo(phi->te, phi, 1);
		// printf("%d last_eat  ouioui: %ld\n", phi->index, phi->last_eat);
		pthread_mutex_unlock(&phi->data->mu_fork[i]);
		if (i == (phi->data->nbr_philos - 1))
			pthread_mutex_unlock(&phi->data->mu_fork[0]);
		else
			pthread_mutex_unlock(&phi->data->mu_fork[i + 1]);
	}
}

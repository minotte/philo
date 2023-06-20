/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:02:01 by nminotte          #+#    #+#             */
/*   Updated: 2023/06/06 10:43:55 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

void	nomber_of_meal(t_philo *phi)
{
	pthread_mutex_lock(&phi->data->all_are_full);
	phi->data->nbr_meal++;
	pthread_mutex_unlock(&phi->data->all_are_full);
}

void	eat_action(t_philo *phi)
{
	ft_msg_philo(phi, FORK);
	ft_msg_philo(phi, EAT);
	pthread_mutex_lock(&phi->l_eat);
	phi->last_eat = what_time(phi->data->time_start);
	pthread_mutex_unlock(&phi->l_eat);
	phi->dinner_nbr++;
}

void	eat(t_philo *phi)
{
	int	i;

	i = phi->index;
	pthread_mutex_lock(&phi->data->mu_fork[i]);
	ft_msg_philo(phi, FORK);
	if (phi->index + 1 == phi->data->nbr_philos)
		pthread_mutex_lock(&phi->data->mu_fork[0]);
	else
		pthread_mutex_lock(&phi->data->mu_fork[i + 1]);
	eat_action(phi);
	if (phi->dinner_nbr == phi->data->must_eat_time)
		nomber_of_meal(phi);
	time_to_spend(phi->data->time_eat, phi->data);
	if (phi->index + 1 == phi->data->nbr_philos)
		pthread_mutex_unlock(&phi->data->mu_fork[0]);
	else
		pthread_mutex_unlock(&phi->data->mu_fork[i + 1]);
	pthread_mutex_unlock(&phi->data->mu_fork[i]);
}

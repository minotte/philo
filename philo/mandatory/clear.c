/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:31:56 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/22 14:38:06 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_clear(t_data_init *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data->mu_fork)
	{
		if (pthread_mutex_destroy(data->mu_fork) != 0)
			printf("error on mutex_destroy\n");
		free (data->mu_fork);
	}
	if (philo)
		free(philo);
	if (data && data->rout_phil)
		free(data->rout_phil);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->dead);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:31:56 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/08 15:52:56 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_clear(t_data_init *data, t_philo *philo)
{
	if (data && data->rout_phil)
		free(data->rout_phil);
	if (philo && philo->mu_fork)
	{
		if(pthread_mutex_destroy(philo->mu_fork) != 0)
			printf("error on mutex_destroy");
	}
}

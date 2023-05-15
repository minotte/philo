/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:31:56 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/15 16:41:46 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"
#include <stdlib.h>

void	ft_clear(t_data_init *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (data->mu_fork)
	{
		if (pthread_mutex_destroy(data->mu_fork) != 0)
			printf("error on mutex_destroy\n");
	}
	if (philo)
		free(philo);
	if (data && data->rout_phil)
		free(data->rout_phil);
}

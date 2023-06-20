/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:42:27 by nminotte          #+#    #+#             */
/*   Updated: 2023/06/05 19:25:51 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

long int	get_time(void)
{
	long long int		time;
	struct timeval		c_time;

	time = 0;
	if (gettimeofday(&c_time, NULL) == 0)
	{
		time = (c_time.tv_usec / 1000) + (c_time.tv_sec * 1000);
		return (time);
	}
	printf("something going wrong with time \n");
	return (0);
}

void	time_to_spend(long int t_spend, t_data_init *data)
{
	long int	time;

	time = get_time();
	while ((get_time() - time) < t_spend)
	{
		usleep(10);
		pthread_mutex_lock(&data->dead);
		if (data->is_dead == 1)
			t_spend = 0;
		pthread_mutex_unlock(&data->dead);
	}
}

long int	what_time(long int time_z)
{
	long int	time;
	long int	time_n;

	time = get_time();
	time_n = time - time_z;
	return (time_n);
}

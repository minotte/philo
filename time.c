/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:42:27 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 17:00:42 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./include/philo.h"

long int	ft_time(void)
{
	long long int		time;
	struct timeval	c_time;

	time = 0;
	if (gettimeofday(&c_time, NULL) == 0)
	{
		time = (c_time.tv_usec / 1000) + (c_time.tv_sec * 1000);
		return (time);
	}
	printf("something going wrong with time \n");
	return (0);
}

long int	time_to_spend(long int time_spend, t_philo *philo)
{
	long long int	time_zero;
	long int	time;

	time_zero = ft_time();
	time = ft_time() - time_zero;
	while (time < time_spend && (philo->data->is_dead == 0))
		time = ft_time() - time_zero;
	// printf("time T : %ld", time_t);
	return (time);
}

long int	what_time(long int time_z)
{
	long int	time;
	long int	time_n;

	time = ft_time();
	time_n = time - time_z;
	return (time_n);
}

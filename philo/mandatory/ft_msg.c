/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:03 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/24 11:19:35 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_msg_philo(t_philo *phi, int status)
{
	long int	time;

	time = what_time(phi->data->time_start);
	pthread_mutex_lock(&phi->data->write);
	pthread_mutex_lock(&phi->data->dead);
	if (phi->data->is_dead == 1)
	{
		pthread_mutex_unlock(&phi->data->write);
		pthread_mutex_unlock(&phi->data->dead);
		return ;
	}	
	pthread_mutex_unlock(&phi->data->dead);
	if (status == 0)
		printf("%s%ld	%d has taken a fork"
			"%s\n", G, time, phi->index + 1, CE);
	if (status == 1)
		printf("%s%ld	%d is eating%s\n", O, time, phi->index + 1, CE);
	if (status == 2)
		printf("%s%ld	%d is sleeping%s\n", B, time, phi->index + 1, CE);
	if (status == 3)
		printf("%s%ld	%d is thinking%s\n", Y, time, phi->index + 1, CE);
	pthread_mutex_unlock(&phi->data->write);
}

void	print_arg_error(void)
{
	ft_putendl_fd("error need more arguments like this :", 2);
	ft_putendl_fd("arg 1 : number of philosophers", 2);
	ft_putendl_fd("arg 2 : time to die", 2);
	ft_putendl_fd("arg 3 : time to eat", 2);
	ft_putendl_fd("arg 4 : time to sleep", 2);
	ft_putendl_fd("(option) arg 5 : "
		"number of times each philosopher must eat", 2);
}

int	wrong_malloc(void *arg)
{
	if (!arg)
	{
		printf("error malloc\n");
		return (1);
	}
	return (0);
}

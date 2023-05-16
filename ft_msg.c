/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:03 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 19:30:32 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// #define ARG_MSG	"time, phi->index + 1, CE"

void	ft_msg_philo(long int time, t_philo *phi, int status)
{
	printf("%d is_dead : %d \n",phi->index, phi->data->is_dead);
	if (phi->data->is_dead == 0)
	{
		pthread_mutex_lock(&phi->data->write);
		time = what_time(phi->data->time_start);
		if (status == 0)
			printf("%s %ld	%d has taken a fork"
				" %s \n", GREEN, time, phi->index + 1, CE);
		if (status == 1)
			printf("%s %ld	%d is eating %s\n", ORANGE, time, phi->index + 1, CE);
		if (status == 2)
			printf("%s %ld	%d is sle%deping %s \n", BLUE, time, phi->index + 1, phi->data->is_dead, CE);
		if (status == 3)
			printf("%s %ld	%d is thin%dking %s \n", YELLOW, time, phi->index + 1,phi->data->is_dead, CE);
		pthread_mutex_unlock(&phi->data->write);
	}
	pthread_mutex_unlock(&phi->data->write);
	pthread_mutex_unlock(&phi->data->dead);
	
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

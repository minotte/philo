/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:03 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/15 17:48:14 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_msg_philo(long int time_ms, t_philo *philo, int status)
{
	if (philo->is_dead == 1)
		return ;
	pthread_mutex_lock(&philo->data->write);
	time_ms = what_time(philo->data->time_start);
	if (status == 0)
		printf("%s %ld	%d has taken a fork %s \n", GREEN, time_ms, philo->index, CE);
	if (status == 1)
		printf("%s %ld	%d is eating %s\n", ORANGE, time_ms, philo->index, CE);
	if (status == 2)
		printf("%s %ld	%d is sleeping %s \n", BLUE, time_ms, philo->index, CE);
	if (status == 3)
		printf("%s %ld	%d is thinking %s \n", YELLOW, time_ms, philo->index, CE);
	pthread_mutex_unlock(&philo->data->write);
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

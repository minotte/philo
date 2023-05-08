/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:03 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/08 11:51:51 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

// void	ft_msg_philo(int time_ms, t_philo philo)
// {
	// ft_printf("%d philo number %d has taken a fork", time_ms, philo.nbr_philos);
	// ft_printf("%d philo number %d is eating", time_ms, philo.nbr_philos);
	// ft_printf("%d philo number %d is sleeping", time_ms, philo.nbr_philos);
	// ft_printf("%d philo number %d is thinking", time_ms, philo.nbr_philos);
	// ft_printf("%d philo number %d died", time_ms, philo.nbr_philos);
// }
// 
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

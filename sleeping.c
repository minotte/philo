/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:16:28 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/15 11:39:47 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*sleeping(t_philo *phi)
{
	int	i;

	i = phi->index;
	// printf("%d is last eat : %ld \n", phi->index, phi->last_eat);
	// phi->ts = ft_time();
	// phi->ts = phi->last_eat;
	ft_msg_philo(phi->te, phi, SLEEP);
	phi->te += time_to_spend(phi->data->time_sleep, phi);
	// ft_msg_philo(phi->ts, phi, 2);
	ft_msg_philo(phi->te, phi, 3);
}

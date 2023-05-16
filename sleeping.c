/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:16:28 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 17:47:50 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	*sleeping(t_philo *phi)
{
	int	i;

	i = phi->index;
	// if (phi->data->is_dead == 0)
	// {
		ft_msg_philo(phi->te, phi, SLEEP);
		phi->te += time_to_spend(phi->data->time_sleep, phi);
		ft_msg_philo(phi->te, phi, THINK);
	// }
}

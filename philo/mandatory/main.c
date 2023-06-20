/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:39:14 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/23 18:53:35 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h" 

int	main(int argc, char **argv)
{
	int			ret;
	t_data_init	data;
	t_philo		*philo;

	philo = NULL;
	data.time_start = get_time();
	ret = parsing(argc, argv, &data);
	if (ret == 0)
	{
		ret = init_data(&data);
		philo = malloc(sizeof(t_philo) * data.nbr_philos);
		if (!philo)
		{
			printf("error malloc\n");
			return (1);
		}	
		ret += init_phi(philo, &data);
		if (ret == 0 && data.nbr_philos == 1)
			ft_philo_one(&data, philo);
		else if (ret == 0 && data.nbr_philos > 1)
			ft_philo(&data, philo);
		ft_clear(&data, philo);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:23:38 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 17:02:55 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*ft_philo(t_data_init *data, t_philo *philo)
{
	int		i;
	int		err;

	data->phi = philo;
	data->rout_phil = malloc(sizeof(pthread_t) * (data->nbr_philos));
	data->all_alive = malloc(sizeof(pthread_t));
	i = 0;
	if (data->nbr_philos == 1)
	{
		err = pthread_create(data->rout_phil + i, NULL, (void *)&rout_phi_one, &philo[i]);
		if (err != 0)
			printf("error on creating of a thread \n");
		if (pthread_join(data->rout_phil[i], NULL) != 0)
			printf("error thread \n");
	}
	else
	{
		while (i < data->nbr_philos)
		{
			// printf("i =%d \n", i);
			err = pthread_create(data->rout_phil + i, NULL, (void *)&routine_philo, &(philo[i]));
			if (err != 0)
			{
				printf("error on creating of a thread \n");
				break ;
			}
			i++;
		}
		err = pthread_create(data->all_alive, NULL, (void *)&all_is_alive, data);
		if (err != 0)
			printf("error on creating of a thread \n");
		i = 0;
		while (i < data->nbr_philos)
		{
			if ((pthread_join(data->rout_phil[i], NULL)) != 0)
			{
				printf("error thread \n");
				break ;
			}
			i++;
		}	
		if ((pthread_join(*data->all_alive, NULL)) != 0)
			printf("error thread \n");

	}
}

t_philo	*init_phi(t_data_init *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nbr_philos);
	if (!philo)
	{
		printf("error malloc\n");
		exit (1);
	}
	if (pthread_mutex_init(&data->dead, NULL) != 0)
	{
		printf("mutex failed\n");
		exit (1);
	}
	if (pthread_mutex_init(&data->write, NULL) != 0)
	{
		printf("mutex failed\n");
		exit (1);
	}
	data->mu_fork = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (!data->mu_fork)
	{
		printf("error malloc\n");
		exit (1);
	}
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&data->mu_fork[i], NULL) != 0)
		{
			printf("mutex failed\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		philo[i].index = i;
		philo[i].dinner_nbr = 0;
		philo[i].data = data;
		philo[i].last_eat = 0;
		philo[i].ts = 0;
		philo[i].te = 0;
		i++;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	t_data_init	data;
	t_philo		*philo;
	int			ret;

	data.time_start = ft_time();
	data.is_dead = 0;
	// printf("time_t : %ld\n", ft_time());
	// printf("time_start  : %ld\n", data.time_start);

	ret = parsing(argc, argv, &data);
	if (ret == 0)
	{
		philo = init_phi(&data);
		ft_philo(&data, philo);
		ft_clear(&data, philo);
	}
	return (ret);
}

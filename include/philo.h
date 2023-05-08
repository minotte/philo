/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:17:02 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/08 19:30:53 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data_init
{
	pthread_t	*rout_phil;
	int			nbr_philos;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			philo_must_eat_time;
}	t_data_init;

typedef struct s_philo
{
	int				index;
	int				rfork;
	int				lfork;
	pthread_mutex_t	*mu_fork;
}	t_philo;
/*
typedef struct s_mutex
{
	pthread_mutex_t	mutex_fork;
	pthread_mutex_t	mutex_sleep;
	pthread_mutex_t	mutex_think;
}	t_mutex;
*/
int		main(int argc, char **argv);
void	print_arg_error(void);
void	ft_msg_philo(int time_ms, t_data_init data);
int		error_not_number(int argc, char **argv);
int		ft_philo_arg(int argc, char **argv, t_data_init *data);
long	ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_clear(t_data_init *data, t_philo *philo);

#endif

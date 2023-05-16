/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:17:02 by nminotte          #+#    #+#             */
/*   Updated: 2023/05/16 16:57:03 by nminotte         ###   ########.fr       */
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

# define CE		"\e[0m"
# define YELLOW	"\e[33m"
# define ORANGE	"\e[35m"
# define RED	"\e[91m"
# define GREEN	"\e[32m"
# define BLUE	"\e[94m"

enum {
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DEAD,
};

typedef struct s_data_init	t_data_init;
typedef struct s_philo
{
	int				index;
	long int		ts;
	long int		te;
	int				dinner_nbr;
	long int		last_eat;
	t_data_init		*data;
	}	t_philo;

struct s_data_init
{
	pthread_t		*rout_phil;
	pthread_t		*all_alive;
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat_time;
	long int		time_start;
	pthread_mutex_t	write;
	pthread_mutex_t	*mu_fork;
	pthread_mutex_t	dead;
	int				is_dead;
	t_philo			*phi;
};

int			main(int argc, char **argv);
void		print_arg_error(void);
void		ft_msg_philo(long int time, t_philo *phi, int status);
int			error_not_number(int argc, char **argv);
int			ft_philo_arg(int argc, char **argv, t_data_init *data);
long		ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
void		ft_clear(t_data_init *data, t_philo *philo);
void		*routine_philo(void *arg);
void		*rout_phi_one(void *arg);
int			parsing(int argc, char **argv, t_data_init *data);
long int	ft_time(void);
long int	time_to_spend(long int time_spend, t_philo *philo);
void		eating(t_philo *phi);
long int	what_time(long int time_z);
void		*sleeping(t_philo *phi);
void		*all_is_alive(void *arg);

#endif

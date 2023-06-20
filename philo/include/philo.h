/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:17:02 by nminotte          #+#    #+#             */
/*   Updated: 2023/06/06 10:42:33 by nminotte         ###   ########.fr       */
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
# define Y	"\e[33m"
# define O	"\e[35m"
# define R	"\e[91m"
# define G	"\e[32m"
# define B	"\e[94m"

enum {
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
};

typedef struct s_data_init
{
	pthread_t		*rout_phil;
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
	pthread_mutex_t	all_are_full;
	int				nbr_meal;
	int				finish;
}	t_data_init;

typedef struct s_philo
{
	int				index;
	int				dinner_nbr;
	long int		last_eat;
	pthread_mutex_t	l_eat;
	t_data_init		*data;
}	t_philo;

int			main(int argc, char **argv);
long int	get_time(void);
int			parsing(int argc, char **argv, t_data_init *data);
long		ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
void		print_arg_error(void);
int			init_phi(t_philo *phi, t_data_init *data);
int			init_data(t_data_init *data);
long int	what_time(long int time_z);
void		ft_clear(t_data_init *data, t_philo *philo);
void		ft_msg_philo(t_philo *phi, int status);
void		*r_philo(void *arg);
void		time_to_spend(long int t_spend, t_data_init *data);
int			wrong_malloc(void *arg);
void		eat(t_philo *phi);
void		ft_philo(t_data_init *d, t_philo *phi);
void		ft_philo_one(t_data_init *data, t_philo *phi);

#endif

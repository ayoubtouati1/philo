/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:25:16 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 22:41:22 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<pthread.h>
# include <sys/time.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<semaphore.h>
# include<signal.h>

typedef struct sema
{
	sem_t			*print;
	sem_t			*lock;
	sem_t			*lock_a;
	sem_t			*forks;
	sem_t			*stop;
	int				eat;
}	t_sema;

typedef struct philosopher
{
	long long		start_time;
	int				members;
	int				index;
	long long		t_eat;
	long long		t_sleep;
	long long		t_die;
	long long		last_t_eat;
	long long		num_of_eat;
	int				must_eat;
	pid_t			id;
	t_sema			*data;
}t_philosopher;

int				ft_atoi(const char *str);
long long		gettime(void);
t_philosopher	*forks_init(t_philosopher *philosopher, t_sema *var, int ac);
void			ft_usleep(long long sleep);
void			norminette(t_philosopher	*philo);
t_philosopher	*initiale_var(char **av, t_philosopher *philos,
					int ac, t_sema *sema);
int				check_die_condition(t_philosopher	*philosopher, int ac2);
int				check_arguments(char **av);
int				is_intiger(char **av);
void			ft_clear(t_philosopher	*philosopher);
void			is_eating(t_philosopher *philo);

#endif
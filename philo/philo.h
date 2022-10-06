/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:25:16 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 15:48:46 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include<pthread.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

# include<pthread.h>
# include <sys/time.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>

typedef struct alleat
{
	int	alleat;
}	t_alleat;

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
	pthread_mutex_t	*forks;
	int				must_eat;
	pthread_mutex_t	*print;
	pthread_mutex_t	*lock;
}	t_philosopher;

int				ft_atoi(const char *str);
long long		gettime(void);
t_philosopher	*forks_init(t_philosopher *var);
void			ft_usleep(long long sleep);
void			norminette(t_philosopher	*philo);
t_philosopher	*initiale_var(char **av, t_philosopher *philos, int ac);
int				check_arguments(char **av);
int				is_intiger(char **av);
void			check_die(t_philosopher *philosopher, int ac2);
void			print_died(t_philosopher *philosopher, int i);
void			ft_clear(t_philosopher	*philosopher, pthread_t	*philo);
int				check_all(t_philosopher *philosopher, int ac2);
void			philosophers(int ac, char **av, int ac2);

#endif
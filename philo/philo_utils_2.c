/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:38:06 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 15:47:09 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philosopher	*initiale_var(char	**av, t_philosopher	*philos, int ac)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].members = ft_atoi(av[1]);
		philos[i].index = i;
		philos[i].start_time = gettime();
		philos[i].t_die = (ft_atoi(av[2]));
		philos[i].t_eat = (ft_atoi(av[3]));
		philos[i].t_sleep = (ft_atoi(av[4]));
		philos[i].must_eat = -1;
		philos[i].num_of_eat = 0;
		if (ac == 6)
			philos[i].must_eat = ft_atoi(av[5]);
		i++;
	}
	return (philos);
}

int	is_eating(t_philosopher *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d take second fork\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d started eating \n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock (philo->print);
	pthread_mutex_lock(philo->lock);
	philo->last_t_eat = gettime();
	pthread_mutex_unlock(philo->lock);
	pthread_mutex_lock(philo->print);
	philo->num_of_eat++;
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->t_eat);
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
	if (philo->num_of_eat >= philo->must_eat && philo->must_eat != -1)
		return (0);
	return (1);
}

void	norminette(t_philosopher	*philo)
{
	if (!is_eating(philo))
		return ;
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d sleeping\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->t_sleep);
	pthread_mutex_lock(philo->print);
	printf("%llu ms   :philo %d thinking\n",
		(gettime() - philo->start_time), philo->index + 1);
	pthread_mutex_unlock(philo->print);
}

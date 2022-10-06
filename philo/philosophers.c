/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:17:17 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 21:56:15 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*routine(void	*philos)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philos;
	while (1)
	{
		if (philo->num_of_eat >= philo->must_eat && philo->must_eat != -1)
			break ;
		pthread_mutex_lock(&philo->forks[philo->index]);
		pthread_mutex_lock(philo->print);
		printf("%llu ms   :philo %d take first fork\n",
			(gettime() - philo->start_time), philo->index + 1);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(&philo->forks[(philo->index + 1) % philo->members]);
		norminette(philo);
	}
	return (NULL);
}

int	check_all(t_philosopher *philosopher, int ac2)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philosopher->print);
	while (philosopher[i].num_of_eat >= philosopher->must_eat && ac2 == 6)
		i++;
	if (i == philosopher->members)
		return (1);
	pthread_mutex_unlock(philosopher->print);
	return (0);
}

long long	timediff(long long past, long long present)
{
	return (present - past);
}

void	philosophers(int ac, char **av, int ac2)
{
	int				i;
	t_philosopher	*philosopher;
	pthread_t		*philo;

	philosopher = malloc (sizeof (t_philosopher) * ft_atoi(av[1]));
	philo = malloc ((sizeof (pthread_t) * ac));
	philosopher = initiale_var(av, philosopher, ac2);
	philosopher = forks_init(philosopher);
	if (philosopher->must_eat == 0)
		return ;
	i = 0;
	while (i < ac)
	{
		philosopher[i].last_t_eat = gettime();
		pthread_create(&philo[i], NULL, &routine, &philosopher[i]);
		i++;
		usleep (100);
	}
	check_die(philosopher, ac2);
	ft_clear(philosopher, philo);
}

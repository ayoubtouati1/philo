/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:36:22 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 15:31:50 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	is_intiger(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] > 57 || av[i][j] < 48) && av[i][j] != 43)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arguments(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		if ((av[i][j - 1] == '+' && av[i][j] == '\0')
			|| (av[i][j - 1] == '-' && av[i][j] == '\0'))
			return (0);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

long long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_philosopher	*forks_init(t_philosopher *var)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print2;
	pthread_mutex_t	*lock2;
	int				i;

	fork = malloc (sizeof(pthread_mutex_t) * var->members);
	print2 = malloc(sizeof(pthread_mutex_t));
	lock2 = malloc(sizeof(pthread_mutex_t) * var->members);
	i = 0;
	pthread_mutex_init(print2, NULL);
	while (i < var->members)
	{
		pthread_mutex_init(&fork[i], NULL);
		pthread_mutex_init(&lock2[i++], NULL);
	}
	i = 0;
	while (i < var->members)
	{
		var[i].lock = lock2;
		var[i].print = print2;
		var[i++].forks = fork;
	}
	return (var);
}

void	ft_usleep(long long sleep)
{
	long long	time;

	time = gettime();
	while (gettime() - time < sleep)
	{
		usleep (250);
	}
}

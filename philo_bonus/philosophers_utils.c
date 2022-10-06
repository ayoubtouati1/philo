/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:36:22 by atouati           #+#    #+#             */
/*   Updated: 2022/09/20 16:18:38 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"
#include<signal.h>

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

t_philosopher	*forks_init(t_philosopher	*philosopher, t_sema *var, int ac)
{
	int		i;

	sem_unlink("lock_a");
	sem_unlink("print");
	sem_unlink("lock");
	sem_unlink("forks");
	sem_unlink("stop");
	var->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	var->forks = sem_open("forks", O_CREAT, S_IRWXU, ac);
	var->lock = sem_open("lock", O_CREAT, S_IRWXU, 1);
	var->lock_a = sem_open("lock_a", O_CREAT, S_IRWXU, 1);
	var->stop = sem_open("stop", O_CREAT, S_IRWXU, 1);
	i = 0;
	while (i < philosopher->members)
	{
		philosopher[i].data = var;
		i++;
	}
	return (philosopher);
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

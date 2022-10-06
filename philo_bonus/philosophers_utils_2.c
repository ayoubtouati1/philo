/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:38:06 by atouati           #+#    #+#             */
/*   Updated: 2022/10/06 00:49:54 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philosopher	*initiale_var(char	**av, t_philosopher	*philos,
		int ac, t_sema	*sema)
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
		philos[i].data = sema;
		if (ac == 6)
			philos[i].must_eat = ft_atoi(av[5]);
		i++;
	}
	return (philos);
}

void	is_eating(t_philosopher *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->print);
	printf("%llu ms   :philo %d take first fork\n",
		(gettime() - philo->start_time), philo->index + 1);
	sem_post(philo->data->print);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->print);
	printf("%llu ms   :philo %d take second fork\n",
		(gettime() - philo->start_time), philo->index + 1);
	sem_post(philo->data->print);
	sem_wait(philo->data->print);
	printf("%llu ms   :philo %d started eating \n",
		(gettime() - philo->start_time), philo->index + 1);
	sem_post (philo->data->print);
	sem_wait(philo->data->lock);
	philo->last_t_eat = gettime();
	sem_post(philo->data->lock);
	ft_usleep(philo->t_eat);
	sem_wait(philo->data->lock_a);
	philo->num_of_eat++;
	sem_post(philo->data->lock_a);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_clear(t_philosopher	*philosopher)
{
	int	i;
	int	a;

	i = 0;
	while (i < philosopher->members)
	{
		waitpid(-1, &a, 0);
		if (a != 0)
		{
			i = -1;
			while (++i < philosopher->members)
			{
				printf("===========>>>>>><<<<<<<===========\n");
				kill(philosopher[i].id, 15);
			}
			break ;
		}
		i++;
	}
	sem_close(philosopher->data->forks);
	sem_close(philosopher->data->lock);
	sem_close(philosopher->data->lock_a);
	sem_close(philosopher->data->print);
	free(philosopher);
}

void	norminette(t_philosopher	*philo)
{
	sem_wait(philo->data->print);
	printf("%llu ms   :philo %d sleeping\n",
		(gettime() - philo->start_time), philo->index + 1);
	sem_post(philo->data->print);
	ft_usleep(philo->t_sleep);
	sem_wait(philo->data->print);
	printf("%llu ms   :philo %d thinking\n",
		(gettime() - philo->start_time), philo->index + 1);
	sem_post(philo->data->print);
}

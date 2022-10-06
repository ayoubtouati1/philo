/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:18:06 by atouati           #+#    #+#             */
/*   Updated: 2022/10/05 15:33:59 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	print_died(t_philosopher *philosopher, int i)
{
	pthread_mutex_lock(philosopher->print);
	printf("%lld ms : philo number %d died \n",
		(gettime() - philosopher->start_time),
		philosopher[i].index + 1);
}

void	check_die(t_philosopher *philosopher, int ac2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!check_all(philosopher, ac2))
	{
		i = 0;
		while ((i < philosopher->members))
		{
			pthread_mutex_lock(philosopher[i].lock);
			if ((gettime() - philosopher[i].last_t_eat) >= philosopher->t_die)
			{
				print_died(philosopher, i);
				j = 1;
				break ;
			}
			pthread_mutex_unlock(philosopher[i].lock);
			i++;
		}
		if (j == 1)
			break ;
	}
}

void	ft_clear(t_philosopher	*philosopher, pthread_t	*philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(philosopher->print);
	pthread_mutex_destroy(philosopher->lock);
	while (i < philosopher->members)
	{
		pthread_detach(philo[i]);
		i++;
	}
	free(philosopher);
}

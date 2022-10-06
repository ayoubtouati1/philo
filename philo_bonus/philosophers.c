/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:17:17 by atouati           #+#    #+#             */
/*   Updated: 2022/10/06 00:54:30 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*check_deth(void	*ptr)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)ptr;
	while (1)
	{
		sem_wait(philosopher->data->lock);
		if ((gettime() - philosopher->last_t_eat) >= philosopher->t_die)
		{
			sem_wait(philosopher->data->print);
			printf("%lld ms : philo number %d died \n",
				(gettime() - philosopher->start_time),
				philosopher->index + 1);
			exit (1);
		}
		sem_post(philosopher->data->lock);
		sem_wait(philosopher->data->lock_a);
		if (philosopher->num_of_eat >= philosopher->must_eat
			&& philosopher->must_eat != -1)
		{
			sem_post(philosopher->data->lock_a);
			break ;
		}
		sem_post(philosopher->data->lock_a);
	}
	return (NULL);
}

void	routine(t_philosopher *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_deth, philo);
	while (1)
	{
		is_eating(philo);
		if (philo->num_of_eat >= philo->must_eat
			&& philo->must_eat != -1)
			break ;
		norminette(philo);
	}
	pthread_join(thread, NULL);
	exit(0);
}

long long	timediff(long long past, long long present)
{
	return (present - past);
}

void	philosophers(int ac, char **av, int ac2)
{
	int				i;
	t_philosopher	*philosopher;
	t_sema			*sema;

	sema = malloc(sizeof(t_sema));
	sema->eat = 0;
	philosopher = malloc (sizeof (t_philosopher) * ft_atoi(av[1]));
	philosopher = initiale_var(av, philosopher, ac2, sema);
	philosopher = forks_init(philosopher, sema, ac);
	if (philosopher->must_eat == 0)
		return ;
	i = 0;
	while (i < ac)
	{
		philosopher[i].last_t_eat = gettime();
		philosopher[i].id = fork();
		if (philosopher[i].id == 0)
			routine(&philosopher[i]);
		i++;
		usleep (100);
	}
	ft_clear(philosopher);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (check_arguments(av) && is_intiger(av))
			philosophers(ft_atoi(av[1]), av, ac);
		else
		{
			printf("There is a problem in arguments\n");
			return (0);
		}
	}
	else
		printf("Error\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouati <atouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:30:33 by atouati           #+#    #+#             */
/*   Updated: 2022/10/04 17:30:57 by atouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

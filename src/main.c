/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:29:58 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 15:54:20 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_forks(t_data *data)
{
	int	i;

	i = 0;
	printf("=== Forks addresses ===\n");
	while (i < data->philo_nbr)
	{
		printf("Philosopher %d:\n", data->philos[i].id);
		printf("  Left  Fork : %p\n", (void *)data->philos[i].left_fork);
		printf("  Right Fork : %p\n", (void *)data->philos[i].right_fork);
		i++;
	}
}
void	destroy_a_table(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
}
int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		parse_line(av, ac);
		data_init(&data, av);
		if (data.philo_nbr == 1)
		{
			printf("%d %d  is thinking\n", 0, 1);
			printf("%d %d  is thinking\n", 0, 1);
			printf("%ld %d  died\n", data.time_to_die / 1000, 1);
			return (0);
		}
		create_table(&data);
		destroy_a_table(&data);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
}

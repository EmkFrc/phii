/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:55:45 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 14:52:06 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*init_fork(int i)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	pthread_mutex_init(&fork->fork, NULL);
	fork->fork_id = i;
	return (fork);
}
void	init_forks(t_data *data, int i)
{
	if (i + 1 == data->philo_nbr)
	{
		data->philos[i].right_fork = init_fork(i);
		data->philos[i].left_fork = data->philos[i - 1].right_fork;
		data->philos[0].left_fork = data->philos[i].right_fork;
	}
	else if (i != 0)
	{
		data->philos[i].right_fork = init_fork(i);
		data->philos[i].left_fork = data->philos[i - 1].right_fork;
	}
	else
	{
		data->philos[i].right_fork = init_fork(i);
	}
}
void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals_counter = 0;
		data->philos[i].full = false;
		pthread_mutex_init(&data->philos[i].philo_mutex, NULL);
		init_forks(data, i);
		i++;
	}
}
void	data_init(t_data *data, char **av)
{
	data->philo_nbr = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) *1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		data->nbr_limit_meals = ft_atol(av[5]);
	else
		data->nbr_limit_meals = -1;
	pthread_mutex_init(&data->data_mutex, NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	data->philos = safe_malloc(sizeof(t_philo) * data->philo_nbr);
	data->start_simulation = 0;
	data->end_simulation = false;
	data->all_thread_ready = false;
	data->full_counter = 0;
	init_philo(data);
}

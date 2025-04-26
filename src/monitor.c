/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:44 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 16:19:55 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	long	time_to_die;
	long	actually;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	time_to_die = philo->data->time_to_die;
	actually = gettime();
	if ((actually - philo->last_meal_time) > time_to_die / 1000)
		return (true);
	else
		return (false);
}
bool	is_full(t_data *data)
{
	if (data->full_counter >= data->philo_nbr)
		return (true);
	else
		return (false);
}
void	*monitor(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	set_long(&data->data_mutex, &data->start_simulation, gettime());
	set_bool(&data->data_mutex, &data->all_thread_ready, true);
	while (!simulation_finish(data))
	{
		i = 0;
		while (i < data->philo_nbr && !simulation_finish(data))
		{
			if (is_dead(&data->philos[i]) == true && !simulation_finish(data))
			{
				printf_log(&data->philos[i], "died");
				set_bool(&data->data_mutex, &data->end_simulation, true);
			}
			i++;
		}
		if (is_full(data))
		{
			set_bool(&data->data_mutex, &data->end_simulation, true);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

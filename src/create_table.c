/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:38:21 by efranco           #+#    #+#             */
/*   Updated: 2025/04/24 19:09:45 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_table(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nbr)
	{
		set_long(&data->philos[i].philo_mutex, &data->philos[i].last_meal_time, gettime());
		pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]);
		i++;
	}

	pthread_create(&data->monitor, NULL, monitor, data);
}

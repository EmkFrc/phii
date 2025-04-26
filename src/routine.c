/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:44:25 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 16:20:40 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	synchro_philos(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(5000);
	}
	else
	{
		usleep(500);
	}
}
void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (get_bool(&philo->philo_mutex, &philo->data->all_thread_ready))
		;
	synchro_philos(philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime());
	while (!simulation_finish(philo->data))
	{
		if (simulation_finish(philo->data) || philo->full)
			break ;
		thinking(philo);
		if (simulation_finish(philo->data) || philo->full)
			break ;
		eating(philo);
		if (simulation_finish(philo->data) || philo->full)
			break ;
		sleeping(philo);
	}
	return (NULL);
}

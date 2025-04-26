/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:17:27 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 16:21:49 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	custom_usleep(t_philo *philo, long time)
{
	long 	start;
	long	actually;

	start = gettime();
	actually = 0;
	while(actually < time / 1000)
	{
		if (simulation_finish(philo->data))
			break ;
		usleep(500);
		actually = gettime() - start;
	}
}
void	eating(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		printf_log(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->fork);
		printf_log(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		printf_log(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->fork);
		printf_log(philo, "has taken a fork");
	}
	if (simulation_finish(philo->data))
	{
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
		return ;
	}
	set_long(&philo->philo_mutex, &philo->last_meal_time , gettime());
	philo->meals_counter++;
	printf_log(philo, "is eating");
	custom_usleep(philo, philo->data->time_to_eat);

	if (philo->data->nbr_limit_meals > 0 && philo->meals_counter == philo->data->nbr_limit_meals)
	{
		set_long(&philo->data->data_mutex, &philo->data->full_counter, philo->data->full_counter + 1);
	}
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return ;
}
void	sleeping(t_philo *philo)
{
	printf_log(philo, "is sleeping");
	custom_usleep(philo, philo->data->time_to_sleep);
}
void	thinking(t_philo *philo)
{
	long	time_to_think;

	time_to_think = (philo->data->time_to_die - (gettime() - philo->last_meal_time) - philo->data->time_to_eat);
	printf_log(philo, "is thinking");
	if (time_to_think < 0)
		time_to_think = 0;
	else if(time_to_think > 600)
		time_to_think = 2;
	custom_usleep(philo, time_to_think * 1000);
}

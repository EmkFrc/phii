/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:41:15 by efranco           #+#    #+#             */
/*   Updated: 2025/04/26 14:55:54 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_log(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (!get_bool(&philo->philo_mutex, &philo->data->end_simulation))
	{
		printf("%ld %d  %s\n", (gettime() - philo->data->start_simulation), philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->write_mutex);
}
int ft_atoi(const char *theString)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || (theString[i] == 32))
		i++;
	if (theString[i] == '-' || theString[i] == '+')
	{
		if (theString[i] == '-')
			sign *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9' && theString[i])
	{
		res = res * 10 + (theString[i] - 48);
		i++;
	}
	return (res * sign);
}
long ft_atol(const char *theString)
{
	long	i;
	long	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || (theString[i] == 32))
		i++;
	if (theString[i] == '-' || theString[i] == '+')
	{
		if (theString[i] == '-')
			sign *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9' && theString[i])
	{
		res = res * 10 + (theString[i] - 48);
		i++;
	}
	return (res * sign);
}
int ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}

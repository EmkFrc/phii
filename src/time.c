/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:59:14 by efranco           #+#    #+#             */
/*   Updated: 2025/04/24 16:33:04 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long 	gettime_us()
{
	struct timeval tv;

    gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1e6) + tv.tv_usec);
}
long	gettime()
{
	struct timeval tv;

    gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

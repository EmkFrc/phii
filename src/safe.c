/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:47:00 by efranco           #+#    #+#             */
/*   Updated: 2025/04/24 16:02:24 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_bool(pthread_mutex_t *mtx, bool *dest, bool value)
{
    pthread_mutex_lock(mtx);
    *dest = value;
    pthread_mutex_unlock(mtx);
}
void set_long(pthread_mutex_t *mtx, long *dest, long value)
{
    pthread_mutex_lock(mtx);
    *dest = value;
    pthread_mutex_unlock(mtx);
}
bool get_bool(pthread_mutex_t *mtx, bool *value)
{
    bool res;
    pthread_mutex_lock(mtx);
    res = *value;
    pthread_mutex_unlock(mtx);
    return (res);
}

long get_long(pthread_mutex_t *mtx, long *value)
{
    long res;

    pthread_mutex_lock(mtx);
    res = *value;
    pthread_mutex_unlock(mtx);
    return (res);
}
bool simulation_finish(t_data *data)
{
    return(get_bool(&data->data_mutex, &data->end_simulation));
}

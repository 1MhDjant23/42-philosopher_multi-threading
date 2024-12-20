/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:54:27 by mait-taj          #+#    #+#             */
/*   Updated: 2024/09/27 21:35:44 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool status, bool *my_bool)
{
	pthread_mutex_lock(mutex);
	*my_bool = status;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(pthread_mutex_t *mutex, bool *my_bool)
{
	bool	ret;

	pthread_mutex_lock(mutex);
	ret = *my_bool;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long val, long *x)
{
	pthread_mutex_lock(mutex);
	*x = val;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *x)
{
	long	ret;

	pthread_mutex_lock(mutex);
	ret = *x;
	pthread_mutex_unlock(mutex);
	return (ret);
}

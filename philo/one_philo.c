/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:55:45 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 19:51:32 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routines_one_p(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	pthread_mutex_lock(&philos->r_fork->mtx);
	ft_print(philos, TAKEN);
	pthread_mutex_unlock(&philos->r_fork->mtx);
	return (NULL);
}

bool	there_is_one_philo(t_program *data)
{
	int	ret;

	set_long(&data->starting, get_time(), &data->start_time);
	ret = pthread_create(&data->philos->tid, NULL, routines_one_p,
			&data->philos[0]);
	if (ret != 0)
		return (false);
	pthread_join(data->philos->tid, NULL);
	pthread_mutex_destroy(&data->philos->r_fork->mtx);
	return (true);
}

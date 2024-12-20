/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:32:07 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 12:57:20 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	assign_forks(t_forks *fork, t_program *data)
{
	int	n_of_p;
	int	i;

	n_of_p = data->n_of_philo;
	i = -1;
	while (++i < n_of_p)
	{
		fork[i].index = i;
		if (pthread_mutex_init(&fork[i].mtx, NULL) != 0)
			return (false);
	}
	if (!assign_enough_mtx(data))
		return (false);
	data->ready = false;
	data->end_simult = false;
	data->start_time = 0;
	return (true);
}

bool	init_resource(t_program *data)
{
	int	n_of_p;
	int	i;

	i = -1;
	n_of_p = data->n_of_philo;
	data->mtx = (t_forks *)malloc(sizeof(t_forks) * n_of_p);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * n_of_p);
	if (!safe_malloc(data->philos, data->mtx))
		return (false);
	while (++i < n_of_p)
		data->philos[i].data = data;
	if (!assign_forks(data->mtx, data))
	{
		free(data->mtx);
		return (free(data->philos), false);
	}
	init_data_of_philo(data, data->mtx);
	return (true);
}

void	init_data_of_philo(t_program *data, t_forks *mtx)
{
	int	i;

	i = -1;
	while (++i < data->n_of_philo)
	{
		data->philos[i].id = i;
		data->philos[i].counter_meals = 0;
		data->philos[i].t_last_meal = get_time();
		data->philos[i].full = false;
		data->philos[i].l_fork = &mtx[i];
		data->philos[i].r_fork = &mtx[(i + 1) % data->n_of_philo];
	}
}

bool	assign_enough_mtx(t_program *data)
{
	if (pthread_mutex_init(&data->print_func, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->death, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->starting, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->all_ready, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->time_l_meal, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->is_full, NULL) != 0)
		return (false);
	return (true);
}

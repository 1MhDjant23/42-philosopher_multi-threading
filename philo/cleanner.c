/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:52:49 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 13:56:01 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_program *data)
{
	int	i;

	i = -1;
	while (++i < data->n_of_philo)
		pthread_mutex_destroy(&data->mtx[i].mtx);
	pthread_mutex_destroy(&data->print_func);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->starting);
	pthread_mutex_destroy(&data->all_ready);
	pthread_mutex_destroy(&data->is_full);
	free(data->mtx);
	free(data->philos);
}

bool	safe_malloc(t_philo *philos, t_forks *mtx)
{
	if (!mtx && !philos)
	{
		printf("malloc faill to alloc mutex and thread\n");
		return (false);
	}
	if (!mtx && philos)
	{
		printf("malloc faill to alloc mutex\n");
		free(philos);
		return (false);
	}
	if (!philos && mtx)
	{
		printf("malloc faill to alloc thread\n");
		free(mtx);
		return (false);
	}
	return (true);
}

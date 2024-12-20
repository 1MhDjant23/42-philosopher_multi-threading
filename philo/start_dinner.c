/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:24:31 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 22:31:04 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_rouitnes(void *arg)
{
	long	n_of_p;
	t_philo	*philos;

	philos = (t_philo *)arg;
	n_of_p = philos->data->n_of_philo;
	while (get_bool(&philos->data->all_ready, &philos->data->ready) == false)
		;
	if ((philos->id + 1) % 2 == 0)
		ft_sleeping(philos);
	while (!get_bool(&philos->data->death, &philos->data->end_simult))
	{
		if (get_bool(&philos->data->is_full, &philos->full))
			break ;
		ft_eating(philos);
		ft_sleeping(philos);
		ft_print(philos, THINK);
	}
	return (NULL);
}

void	joint_thread(t_program *data)
{
	int	i;

	i = -1;
	while (++i < data->n_of_philo)
		pthread_join(data->philos[i].tid, NULL);
	ft_destroy(data);
}

bool	starting_dinner(t_program *data)
{
	int	i;

	if (data->n_of_philo == 1)
	{
		if (!there_is_one_philo(data))
			return (false);
	}
	else
	{
		if (!create_thread(data))
			return (false);
	}
	while (!get_bool(&data->death, &data->end_simult))
	{
		i = -1;
		while (++i < data->n_of_philo)
		{
			if (is_death(&data->philos[i]) == true)
				break ;
			if (data->limit_of_meals != -1 && all_philo_full(data) == true)
				break ;
		}
	}
	joint_thread(data);
	return (true);
}

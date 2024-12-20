/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:02:20 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 23:18:42 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philos)
{
	if (get_bool(&philos->data->death, &philos->data->end_simult))
		return ;
	pthread_mutex_lock(&philos->r_fork->mtx);
	ft_print(philos, TAKEN);
	pthread_mutex_lock(&philos->l_fork->mtx);
	ft_print(philos, TAKEN);
	ft_print(philos, EAT);
	ft_sleep(philos->data->t_to_eat, philos->data);
	philos->counter_meals += 1;
	set_long(&philos->data->time_l_meal, get_time(), &philos->t_last_meal);
	if (philos->counter_meals == philos->data->limit_of_meals)
		set_bool(&philos->data->is_full, true, &philos->full);
	pthread_mutex_unlock(&philos->r_fork->mtx);
	pthread_mutex_unlock(&philos->l_fork->mtx);
}

void	ft_sleeping(t_philo *philos)
{
	if (get_bool(&philos->data->death, &philos->data->end_simult))
		return ;
	else
	{
		ft_print(philos, SLEEP);
		ft_sleep(philos->data->t_to_sleep, philos->data);
	}
}

bool	is_death(t_philo *philos)
{
	if (get_time() - get_long(&philos->data->time_l_meal,
			&philos->t_last_meal) >= philos->data->t_to_die)
	{
		ft_print(philos, DEAD);
		set_bool(&philos->data->death, true, &philos->data->end_simult);
		return (true);
	}
	return (false);
}

bool	all_philo_full(t_program *data)
{
	int	n_of_p;
	int	i;

	n_of_p = data->n_of_philo;
	if (data->limit_of_meals != -1)
	{
		i = -1;
		while (++i < n_of_p)
		{
			if (get_bool(&data->is_full, &data->philos[i].full) == false)
				break ;
		}
		if (i == n_of_p)
		{
			set_bool(&data->death, true, &data->end_simult);
			return (true);
		}
	}
	return (false);
}

bool	base_case(t_program *data, t_enum stat)
{
	if (get_bool(&data->death, &data->end_simult) && stat != DEAD)
	{
		pthread_mutex_unlock(&data->print_func);
		return (true);
	}
	return (false);
}

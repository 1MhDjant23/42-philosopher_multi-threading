/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:23:02 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 22:31:12 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_data(char **av, t_program *data)
{
	data->n_of_philo = ft_atol(av[1]);
	data->t_to_die = ft_atol(av[2]);
	data->t_to_eat = ft_atol(av[3]);
	data->t_to_sleep = ft_atol(av[4]);
	if (!av[5])
		data->limit_of_meals = -1;
	else
		data->limit_of_meals = ft_atol(av[5]);
	if (data->n_of_philo > INT_MAX || data->n_of_philo <= 0)
		return (false);
	else if (data->t_to_die > INT_MAX)
		return (false);
	if (data->t_to_eat > INT_MAX)
		return (false);
	if (data->t_to_sleep > INT_MAX)
		return (false);
	return (true);
}

bool	create_thread(t_program *data)
{
	int	i;
	int	n_of_p;
	int	ret;

	i = -1;
	n_of_p = data->n_of_philo;
	set_long(&data->starting, get_time(), &data->start_time);
	while (++i < n_of_p)
	{
		ret = pthread_create(&data->philos[i].tid, NULL, start_rouitnes, &data
				->philos[i]);
		if (ret != 0)
			return (false);
	}
	set_bool(&data->all_ready, true, &data->ready);
	return (true);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(long x, t_program *data)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < x)
	{
		if (get_bool(&data->death, &data->end_simult))
			return ;
		usleep(500);
	}
}

void	ft_print(t_philo *philos, t_enum status)
{
	long	start;

	pthread_mutex_lock(&philos->data->print_func);
	if (base_case(philos->data, status))
		return ;
	start = get_long(&philos->data->starting, &philos->data->start_time);
	if (status == EAT)
		printf("%ld %d is eating\n", get_time()
			- start, philos->id + 1);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", get_time()
			- start, philos->id + 1);
	else if (status == THINK)
		printf("%ld %d is thinking\n", get_time()
			- start, philos->id + 1);
	else if (status == DEAD)
		printf("%ld %d "RED"is died"RESET"\n", get_time()
			- start, philos->id + 1);
	else if (status == TAKEN)
		printf("%ld %d has taken a fork\n", get_time()
			- start, philos->id + 1);
	pthread_mutex_unlock(&philos->data->print_func);
}

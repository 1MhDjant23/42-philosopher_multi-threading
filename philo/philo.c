/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:52:06 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 22:35:46 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	data;

	if (argc != 5 && argc != 6)
		return (err_input(INP), 1);
	if (!checking_valid_input(argv))
		return (err_input(INV), 1);
	if (!init_data(argv, &data))
		return (err_input(INIT), 1);
	if (data.limit_of_meals == 0)
	{
		printf(""UNDER BOLD"give at least one meal to philo"RESET"\n");
		return (1);
	}
	if (!init_resource(&data))
		return (err_input(RES), 1);
	if (!starting_dinner(&data))
	{
		ft_destroy(&data);
		return (err_input(DIN), 1);
	}
	return (0);
}

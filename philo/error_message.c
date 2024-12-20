/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:13:24 by mait-taj          #+#    #+#             */
/*   Updated: 2024/09/27 21:35:09 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_input(t_enum stat)
{
	if (stat == INP)
	{
		printf(""YELL BOLD"Usage:"RESET" ./philo num_of_philo ");
		printf("time_to_die time_to_eat");
		printf(" time_to_sleep ["UNDER BOLD"n_of_meals"RESET"]\n");
	}
	else if (stat == INV)
	{
		printf(""RED BOLD"Oops!!"RESET" "BOLD"enter only ");
		printf("positive digit"RESET"\n");
	}
	else if (stat == INIT)
	{
		printf(""BOLD RED"Oops!!"RESET" "BOLD"number you ");
		printf("entered most be integer and sup strict to 0"RESET"\n");
	}
	else if (stat == RES)
		printf(""BOLD"Error Occur in mutex initialization"RESET"\n");
	else if (stat == DIN)
		printf(""BOLD"Oops!!"RESET" Error occur when thread's starting!\n");
	return ;
}

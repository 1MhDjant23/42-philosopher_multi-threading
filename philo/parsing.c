/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:09:54 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 22:15:42 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

long	ft_atol(char *str)
{
	long	res;
	int		signe;

	signe = 1;
	res = 0;
	while (*str && is_space(*str) == true)
		str++;
	if (*str == '-' || *(str) == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * signe);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && is_space(str[i]) == true)
		i++;
	if (str[i] == '+')
		i++;
	return (i);
}

bool	checking_valid_input(char **av)
{
	int	ac;
	int	i;

	ac = 0;
	while (av[++ac])
	{
		i = skip_space(av[ac]);
		while (av[ac][i])
		{
			if (av[ac][i] >= '0' && av[ac][i] <= '9')
				i++;
			else
				break ;
		}
		while (av[ac][i])
		{
			if (is_space(av[ac][i]) == true)
				i++;
			else
				return (false);
		}
	}
	return (true);
}

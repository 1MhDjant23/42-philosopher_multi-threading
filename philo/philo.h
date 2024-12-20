/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:52:30 by mait-taj          #+#    #+#             */
/*   Updated: 2024/12/18 23:08:15 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define YELL "\033[33m"
# define BOLD "\033[1m"
# define UNDER "\033[4m"

typedef struct s_philo	t_philo;

typedef enum s_enum
{
	EAT,
	THINK,
	SLEEP,
	TAKEN,
	DEAD,
	INV,
	INP,
	INIT,
	RES,
	DIN,
}				t_enum;

/*__________________________ Struct for Mutex_______________________________*/

typedef struct s_forks
{
	int				index;
	pthread_mutex_t	mtx;
}				t_forks;

/*____________________ Struct for Programme_________________________________*/

typedef struct s_program
{
	long			n_of_philo;
	long			t_to_eat;
	long			t_to_sleep;
	long			limit_of_meals;
	long			t_to_die;
	long			start_time;
	bool			end_simult;
	bool			ready;
	pthread_mutex_t	print_func;
	pthread_mutex_t	death;
	pthread_mutex_t	starting;
	pthread_mutex_t	all_ready;
	pthread_mutex_t	time_l_meal;
	pthread_mutex_t	is_full;
	t_philo			*philos;
	t_forks			*mtx;
}					t_program;

/*________________ Struct for philosopher________________________________*/

struct s_philo
{
	int			id;
	long		counter_meals;
	long		t_last_meal;
	bool		full;
	pthread_t	tid;
	t_forks		*r_fork;
	t_forks		*l_fork;
	t_program	*data;
};

/*+++++++++++++++++++ SAFE FUNCTION +++++++++++++++++++++++++++++++++++*/

void	ft_destroy(t_program *data);
bool	safe_malloc(t_philo *philos, t_forks *mtx);
bool	base_case(t_program *data, t_enum stat);
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*********************** PARSING ***************************************/

bool	checking_valid_input(char **av);
long	ft_atol(char *str);

/***********************************************************************/

/**----------- INITIALIZATION INPUT ----------------------------------**/

bool	init_data(char **av, t_program *data);
void	ft_sleep(long x, t_program *data);

/**-------------------------------------------------------------------**/

/*$$$$$$$$$$ INIT RESOURCES (THREAD'S && MUTEX) $$$$$$$$$$$$$$$$$$$$$$$*/

bool	init_resource(t_program *philos);
bool	create_thread(t_program *data);
void	*start_rouitnes(void *arg);
void	ft_eating(t_philo *philos);
void	ft_sleeping(t_philo *philos);
long	get_time(void);
void	ft_print(t_philo *philos, t_enum status);
bool	starting_dinner(t_program *data);
bool	is_death(t_philo *philos);
bool	all_philo_full(t_program *data);
bool	assign_enough_mtx(t_program *data);
void	init_data_of_philo(t_program *data, t_forks *mtx);
bool	there_is_one_philo(t_program *data);

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

/*%%%%%%%%%%% SETTERS && GETTERS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
void	set_bool(pthread_mutex_t *mutex, bool status, bool *my_bool);
bool	get_bool(pthread_mutex_t *mutex, bool *my_bool);
void	set_long(pthread_mutex_t *mutex, long val, long *x);
long	get_long(pthread_mutex_t *mutex, long *x);
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*############### ERROR MESSAGE #####################################*/
void	err_input(t_enum stat);
/*###################################################################*/

#endif
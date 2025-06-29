/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:58 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 22:13:34 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INFO: includes
/*-----------------------------------------------*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

// INFO: redifine/define
/*-----------------------------------------------*/
typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

// INFO: colors
/*-----------------------------------------------*/
# ifndef BLUE
#  define BLUE  "\001\033[34m\002"
# endif
# ifndef GREEN
#  define GREEN "\001\033[32m\002"
# endif
# ifndef RED
#  define RED   "\001\033[31m\002"
# endif
# ifndef YELLOW
#  define YELLOW "\001\033[0;33m\002"
# endif
# ifndef RESET
#  define RESET "\001\033[0m\002"
# endif

typedef enum s_philo_stat
{
	TAKEN_A_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_philo_stat;

// INFO: philosopher struct
/*-----------------------------------------------*/
typedef struct s_philosopher
{
	int			id;
	t_mutex		*first_fork;
	t_mutex		*second_fork;
	bool		full; // the optional argument
	bool		died;
	int			meals_counter;
	long		last_meal_time;
	t_mutex		philo_mutex; // avoid data race with the monitor
	t_table		*table; // pointer to the table (access data)
	pthread_t	thread; // the philosopher (thread)
}	t_philosopher;

// INFO: table struct (user input)
// ./philo 5 800 200 200 [5]
/*-----------------------------------------------*/
struct s_table
{
	long			philo_nbr; // TODO: check subject for max philo (250)
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals; // [5] optional argument
	long			start_dinner; // at what time the dinner started
	bool			end_dinner; // if a philo dies or all philos are full
	bool			all_philos_ready; // to sync all philos
	t_mutex			table_mutex; // avoid data_race if reading from table
	t_mutex			write_mutex; // avoid data_race if writing the status
	long			nbr_of_philos_dining; // number of philos started dining
	pthread_t		butler; // this will check for dead philos
	t_mutex			*forks; //array of forks
	t_philosopher	*philos; // array of philosophers
};

// INFO: functions
/*-----------------------------------------------*/
// INFO: error_printers
void	parce_error_1(int error_mssg);
void	parce_error_2(int error_mssg);
void	init_error_1(int error_mssg);

// INFO: parcing functions
bool	parce_args(int argc, char **argv, t_table *table);
long	ft_atol(char *arg);

// INFO: initializing functions
bool	data_init(t_table *table);

// INFO: data_race safe read and change functions
void	change_bool(t_mutex *mutex, bool *to_change, bool value);
void	change_long(t_mutex *mutex, long *to_change, long value);
void	increment_long(t_mutex *mutex, long *to_increment);
bool	read_bool(t_mutex *mutex, bool *value);
long	read_long(t_mutex *mutex, long *value);

bool	end_dinner(t_table *table);

// INFO: synchronisation functions
void	wait_philos(t_table *table);

// INFO: time functions
long	gettime(void);
void	ft_sleep(long milliseconds, t_philosopher *philo);

// INFO: print status function
void	print_status(t_philo_stat stat, t_philosopher *philo);

// INFO: dinner simulation function
void	*philo_routine(void *ptr);
void	dinner_simulation(t_table *table);
void	*butler_service(void *ptr);
void	one_philo(t_table *table);

// INFO: clean_up
void	clean_up(t_table *table);

/*-----------------------------------------------*/

#endif

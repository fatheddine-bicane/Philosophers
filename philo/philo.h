/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:58 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/21 18:36:18 by fbicane          ###   ########.fr       */
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

// INFO: fork struct
/*-----------------------------------------------*/
typedef struct s_fork
{
	int		fork_id;
	t_mutex	mutex;
}	t_fork;


// INFO: philosopher struct
/*-----------------------------------------------*/
typedef struct s_philosopher
{
	int			id;
	t_fork		right_fork;
	t_fork		left_fork;
	bool		full; // the optional argument
	bool		died;
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
	long			start_dinner; // maybe at what time to start dinner
	bool			end_dinner; // when a philosopher dies or all of them are full
	t_fork			*forks; //array of forks
	t_philosopher	philos; // array of philosophers
};

// INFO: functions
/*-----------------------------------------------*/
// INFO: error_printers
void	parce_error_1(int error_mssg);

// INFO: parcing functions
bool	parce_args(int argc, char **argv, t_table *table);
long	ft_atol(char *arg);
#endif

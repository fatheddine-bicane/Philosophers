/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:11:54 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/29 15:52:35 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

// INFO: table struct (user input)
// ./philo 5 800 200 200 [5]
/*-----------------------------------------------*/
typedef struct s_table
{
	long			philo_nbr; // TODO: check subject for max philo (250)
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals; // [5] optional argument
	long			start_dinner; // at what time the dinner started
	bool			end_dinner; // if a philo dies or all philos are full
	bool			all_philos_ready; // to sync all philos
	long			nbr_of_philos_dining; // number of philos started dining
	pthread_t		butler; // this will check for dead philos
}	t_table;


// INFO: functions
/*-----------------------------------------------*/
// INFO: error_printers
void	parce_error_1(int error_mssg);
void	parce_error_2(int error_mssg);

// INFO: parcing functions
bool	parce_args(int argc, char **argv, t_table *table);
long	ft_atol(char *arg);
/*-----------------------------------------------*/

#endif

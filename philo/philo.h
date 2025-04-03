/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:45:08 by fbicane           #+#    #+#             */
/*   Updated: 2025/03/07 20:16:03 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //usleep
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h> //mutex, thread
# include <sys/time.h> //gettimeofday

typedef struct args_s
{
	unsigned int		number_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	meals_must_eat;
	bool	optional_argumen;
}	args_t;

/*typedef struct philo_s*/
/*{*/
/**/
/*}*/

void	ft_throw_error_1(int error, args_t *args);

bool	ft_syntax_error(char *argv);
unsigned long	ft_atol(const char *str);

#endif

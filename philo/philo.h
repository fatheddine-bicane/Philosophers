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
# include <limits.h>
# include <stdbool.h>
# include <pthread.h> //mutex, thread
# include <sys/time.h> //gettimeofday

typedef struct s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	timeval_t;

/*typedef struct philo_s*/
/*{*/
/**/
/*}*/

void	ft_throw_error_1(int error);

#endif

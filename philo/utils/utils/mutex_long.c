/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:50:18 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/29 13:51:26 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// INFO: change long value to_change, avoiding data race
void	change_long(t_mutex *mutex, long *to_change, long value)
{
	pthread_mutex_lock(mutex);
	*to_change = value;
	pthread_mutex_unlock(mutex);
}

// INFO: increment long
void	increment_long(t_mutex *mutex, long *to_increment)
{
	pthread_mutex_lock(mutex);
	(*to_increment)++;
	pthread_mutex_unlock(mutex);
}

// INFO: read the value and avoid data race
long	read_long(t_mutex *mutex, long *value)
{
	long	result;

	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	return (result);
}

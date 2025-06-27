/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_read_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:16 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/27 09:56:24 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// INFO: change boolean value to_change, avoiding data race
void	change_bool(t_mutex *mutex, bool *to_change, bool value)
{
	pthread_mutex_lock(mutex);
	*to_change = value;
	pthread_mutex_unlock(mutex);
}

// INFO: change long value to_change, avoiding data race
void	change_long(t_mutex *mutex, long *to_change, long value)
{
	pthread_mutex_lock(mutex);
	*to_change = value;
	pthread_mutex_unlock(mutex);
}

// INFO: read boolean value and avoid data race
bool	read_bool(t_mutex *mutex, bool *value)
{
	bool	result;

	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	return (result);
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

bool	end_dinner(t_table *table)
{
	return (read_bool(&table->table_mutex, &table->end_dinner));
}

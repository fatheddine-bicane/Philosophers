/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:19:45 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 21:26:48 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

// INFO: a precise sleep function
void	ft_sleep(long milliseconds, t_philosopher *philo)
{
	long	start;
	(void)philo;

	start = gettime();
	if (NULL == philo)
	{
		while ((gettime() - start) < milliseconds)
			usleep(500);
		return ;
	}
	while ((gettime() - start) < milliseconds)
	{
		// TODO: keep checking against end_dinner
		if (false == read_bool(&philo->table->table_mutex,
			&philo->table->end_dinner))
			usleep(10);
		else
			return ;
	}
}

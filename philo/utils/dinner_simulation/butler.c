/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:02:41 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 11:08:47 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static bool all_philos_dining(t_mutex *mutex, long *philos_dining, long philos_nbr)
{
	bool	result;

	result = false;
	pthread_mutex_lock(mutex);
	if ((*philos_dining) == philos_nbr)
		result = true;
	pthread_mutex_unlock(mutex);
	return (result);
}

static bool	is_philo_dead(t_philosopher *philo)
{
	long	last_meal;
	long	time_to_die;

	if (true == read_bool(&philo->philo_mutex, &philo->full))
		return (false);
	last_meal = gettime() - read_long(&philo->philo_mutex, &philo->last_meal_time);
	time_to_die = read_long(&philo->table->table_mutex, &philo->table->time_to_die);
	// time_to_die = philo->table->time_to_die;
	if (last_meal > time_to_die)
		return (true);
	return (false);
}

static bool	are_philos_full(t_table *table)
{
	int	i;
	int	nbr_philos_full;

	i = 0;
	nbr_philos_full = 0;
	while (i < table->philo_nbr)
	{
		if (true == read_bool(&table->philos[i].philo_mutex, &table->philos[i].full))
			nbr_philos_full++;
		i++;
	}
	if (nbr_philos_full == i)
		return (true);
	return (false);
}

void	*butler_service(void *ptr)
{
	t_table	*table;
	int		i;

	table = (t_table *)ptr;
	while (false == all_philos_dining(&table->table_mutex, &table->nbr_of_philos_dining, table->philo_nbr))
		;
	while (false == end_dinner(table))
	{
		i = 0;
		//check every philosopher in the table if he died
		while (i < table->philo_nbr && false == end_dinner(table))
		{
			if (true == are_philos_full(table))
				return (NULL);
			if (true == is_philo_dead(table->philos + i))
			{
				change_bool(&table->table_mutex, &table->end_dinner, true);
				print_status(DIED, table->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}


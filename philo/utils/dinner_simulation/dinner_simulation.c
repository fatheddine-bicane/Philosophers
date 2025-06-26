/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:55:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/25 20:52:47 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	create_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (0 != pthread_create(&table->philos[i].thread,
				NULL, dinner_routine, &table->philos[i]))
				return (dinner_error_1(1), false);
		i++;
	}
	return (true);
}

bool	join_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (0 != pthread_join(table->philos[i].thread, NULL))
			return (false);
		i++;
	}
	return (true);
}

bool	dinner_simulation(t_table *table)
{
	if (1 == table->limit_meals)
	{
		// TODO: edge case one philo will starve to death
	}

	if (false == create_philos(table))
		return (false);

	table->start_dinner = gettime();
	if (-1 == table->start_dinner)
		return (false);

	change_bool(&table->table_mutex, &table->all_philos_ready, true);

	join_philos(table);
	// if we reach this line all philosophers are full


	return (true);
}

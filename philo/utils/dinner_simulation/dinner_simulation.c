/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:55:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/24 17:13:21 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*dinner_routine(void *ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)ptr;
	return (NULL);
}

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

bool	dinner_simulation(t_table *table)
{
	/*if (1 == table->limit_meals)*/
		// edge case maybe




	if (false == create_philos(table))
		return (false);



	return (true);
}

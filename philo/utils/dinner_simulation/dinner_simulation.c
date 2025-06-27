/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:55:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/27 20:23:05 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	create_philos(t_table *table)
{
	t_philosopher	*philo;
	pthread_t		*philo_thread;
	int				i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo_thread = &table->philos[i].thread;
		philo = &table->philos[i];
		pthread_create(philo_thread, NULL, philo_routine, philo);
		i++;
	}
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

void	dinner_simulation(t_table *table)
{
	if (1 == table->philo_nbr)
	{
		printf(YELLOW"%-6d"BLUE" 1"RESET " has taken a fork\n", 0);
		ft_sleep(table->time_to_die);
		printf(YELLOW"%-6ld" BLUE" 1" RED" died\n"RESET, table->time_to_die);
		return;
	}
	create_philos(table);
	pthread_create(&table->butler, NULL, butler_service, table);
	table->start_dinner = gettime();
	change_bool(&table->table_mutex, &table->all_philos_ready, true);
	join_philos(table);
	// pthread_join(table->butler, NULL);
	// if we reach this line all philosophers are full
}

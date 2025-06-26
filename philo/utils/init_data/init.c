/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/25 20:57:28 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static bool	fork_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (0 != pthread_mutex_init(&table->forks[i].fork, NULL))
			return (init_error_1(1), false);
		table->forks[i].fork_id = i;
		i++;
	}
	return (true);
}

static void	asign_forks(t_philosopher *philo, t_fork *forks, int i)
{
	if (0 == philo->id % 2)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo->table->philo_nbr];
	}
	else
	{
		philo->second_fork = &forks[i];
		philo->first_fork = &forks[(i + 1) % philo->table->philo_nbr];
	}
}

static bool	philos_init(t_table *table)
{
	int	i;
	t_philosopher	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i; // access each philo in the array one by one
		philo->died = false;
		philo->full = false;
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->last_meal_time = 0;
		philo->table = table;
		asign_forks(philo, table->forks, i);
		i++;
	}
	return (true);
}

bool	data_init(t_table *table)
{
	table->end_dinner = false;
	table->all_philos_ready = false;
	if (0 != pthread_mutex_init(&table->table_mutex, NULL))
		return (init_error_1(1), false);
	if (0 != pthread_mutex_init(&table->write_mutex, NULL))
		return (init_error_1(1), false);
	table->philos = malloc(sizeof(t_philosopher) * table->philo_nbr);
	if (NULL == table->philos)
		return (false); // TODO: error mssg
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (NULL == table->forks)
		return (false); // TODO: error mssg
	if (false == fork_init(table))
		return (false);
	if (false == philos_init(table))
		return (false);
	return (true);
}

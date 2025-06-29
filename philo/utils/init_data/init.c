/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:45:35 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 21:59:28 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	fork_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

static void	asign_forks(t_philosopher *philo, int i, long philo_nbr)
{
	t_mutex	*forks;

	forks = philo->table->forks;
	if (0 == philo->id % 2)
	{
		if (philo->id == philo_nbr)
		{
			philo->first_fork = &forks[i];
			philo->second_fork = &forks[0];
			return ;
		}
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[philo->id];
	}
	else
	{
		if (philo->id == philo_nbr)
		{
			philo->first_fork = &forks[0];
			philo->second_fork = &forks[i];
			return ;
		}
		philo->first_fork = &forks[philo->id];
		philo->second_fork = &forks[i];
	}
}

static void	philos_init(t_table *table)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = &table->philos[i]; // access each philo in the array one by one
		philo->died = false;
		philo->full = false;
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->last_meal_time = 0;
		pthread_mutex_init(&philo->philo_mutex, NULL);
		philo->table = table;
		asign_forks(philo, i, table->philo_nbr);
		i++;
	}
}

bool	data_init(t_table *table)
{
	table->forks = NULL;
	table->philos = NULL;
	table->end_dinner = false;
	table->all_philos_ready = false;
	pthread_mutex_init(&table->table_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
	table->philos = malloc(sizeof(t_philosopher) * table->philo_nbr);
	if (NULL == table->philos)
		return (init_error_1(1), false);
	table->forks = malloc(sizeof(t_mutex) * table->philo_nbr);
	if (NULL == table->forks)
		return (init_error_1(1), false);
	table->nbr_of_philos_dining = 0;
	fork_init(table);
	philos_init(table);
	return (true);
}

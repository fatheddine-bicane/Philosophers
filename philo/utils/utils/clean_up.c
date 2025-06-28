/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:59:20 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 21:58:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	clean_forks(t_table *table, t_mutex *forks)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

static void	clean_philos(t_table *table, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&philos[i].philo_mutex);
		i++;
	}
}

void	clean_up(t_table *table)
{
	t_philosopher	*philos;
	t_mutex			*forks;

	philos = table->philos;
	forks = table->forks;
	if (NULL != table->forks)
		clean_forks(table, forks);
	if (NULL != table->philos)
		clean_philos(table, philos);
	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_mutex);
	free(forks);
	free(philos);
}

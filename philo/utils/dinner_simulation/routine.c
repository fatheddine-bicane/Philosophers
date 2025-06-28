/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:52:39 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/27 20:12:41 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	eating(t_philosopher *philo)
{
	// take forks
	pthread_mutex_lock(philo->first_fork);
	print_status(TAKEN_A_FORK, philo);
	pthread_mutex_lock(philo->second_fork);
	print_status(TAKEN_A_FORK, philo);
	// eat
	change_long(&philo->philo_mutex, &philo->last_meal_time, gettime());
	philo->meals_counter++;
	print_status(EATING, philo);
	ft_sleep(philo->table->time_to_eat, philo);
	//check if philosopher is full
	if (philo->table->limit_meals > 0
		&& philo->meals_counter == philo->table->limit_meals)
		change_bool(&philo->philo_mutex, &philo->full, true);
	// put forks on table
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}

static void	thinking(t_philosopher *philo)
{
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;

	print_status(THINKING, philo);
	if (0 == philo->table->philo_nbr % 2)
		return ;
	else
	{
		time_to_eat = read_long(&philo->table->table_mutex, &philo->table->time_to_eat);
		time_to_sleep = read_long(&philo->table->table_mutex, &philo->table->time_to_sleep);
		time_to_think = time_to_eat * 2 - time_to_sleep;
		if (0 > time_to_think)
			time_to_think = 0;
		ft_sleep(time_to_think, philo);
	}
}

void	*philo_routine(void *ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)ptr;
	// wait until all philos are created
	wait_philos(philo->table);
	// set last meal time
	change_long(&philo->philo_mutex, &philo->last_meal_time, gettime());
	// increment the value in table, the butler wont be able to start
	// untet all philos are ready (nbr_of_philos_runing == philo_nbr)
	increment_long(&philo->table->table_mutex,
		&philo->table->nbr_of_philos_dining);

	// the routine start, stops if the flag setted to false
	while (false == end_dinner(philo->table))
	{
		// philo is full (has eaten limit meals)
		if (true == philo->full)
			break ;
		// eating
		eating(philo);
		// sleep
		print_status(SLEEPING, philo);
		ft_sleep(philo->table->time_to_sleep, philo);
		// think
		thinking(philo);
	}
	return (NULL);
}

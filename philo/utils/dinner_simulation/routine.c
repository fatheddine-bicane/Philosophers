/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:52:39 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/25 20:53:54 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static bool	eating(t_philosopher *philo)
{
	if (0 != pthread_mutex_lock(&philo->first_fork->fork))
		return (false);
	if (false == print_status(TAKEN_A_FORK, philo))
		return (false);
	if (0 != pthread_mutex_lock(&philo->second_fork->fork))
		return (false);
	if (false == print_status(TAKEN_A_FORK, philo))
		return (false);
	change_long(&philo->philo_mutex, &philo->last_meal_time, gettime());
	philo->meals_counter++;
	if (false == print_status(EATING, philo))
		return (false);
	ft_sleep(philo->table->time_to_eat);
	if (philo->table->limit_meals > 0
		&& philo->meals_counter == philo->table->limit_meals)
		change_bool(&philo->philo_mutex, &philo->full, true);
	if (0 != pthread_mutex_unlock(&philo->first_fork->fork))
		return (false);
	if (0 != pthread_mutex_unlock(&philo->second_fork->fork))
		return (false);

	return (true);
}

void	*dinner_routine(void *ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)ptr;
	// wait until all philos are created
	wait_philos(philo->table);
	// the routine start, stops if the flag setted to false
	while (false == end_dinner(philo->table))
	{
		// philo is full (has eaten limit meals)
		if (true == philo->full)
			break ;
		// eating
		if (false == eating(philo))
			return (NULL);
		// sleep
		if (false == print_status(SLEEPING, philo))
			return (NULL); // maybe use join to check for false chain
		ft_sleep(philo->table->time_to_sleep);
		// think
		print_status(THINKING, philo);
	}

	return (NULL);
}

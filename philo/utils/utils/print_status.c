/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:24:37 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/25 20:39:23 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"


bool	print_status(t_philo_stat stat, t_philosopher *philo)
{
	long	curent_time;

	if (true == philo->full)
		return (true);
	if (0 != pthread_mutex_lock(&philo->table->write_mutex))
		return (false);
	if (TAKEN_A_FORK == stat && false == end_dinner(philo->table))
		printf(YELLOW"%-6ld"RESET BLUE" %d"RESET " has taken a fork\n", curent_time, philo->id);
	else if (EATING == stat && false == end_dinner(philo->table))
		printf(YELLOW"%-6ld"RESET BLUE" %d"RESET " is eating\n", curent_time, philo->id);
	else if (SLEEPING == stat && false == end_dinner(philo->table))
		printf(YELLOW"%-6ld"RESET BLUE" %d"RESET " is sleeping\n", curent_time, philo->id);
	else if (THINKING == stat && false == end_dinner(philo->table))
		printf(YELLOW"%-6ld"RESET BLUE" %d"RESET " is thinking\n", curent_time, philo->id);
	else if (DIED == stat)
		printf(YELLOW"%-6ld"RESET BLUE" %d"RESET " died\n", curent_time, philo->id);
	if (0 != pthread_mutex_unlock(&philo->table->write_mutex))
		return (false);
	return (true);
}

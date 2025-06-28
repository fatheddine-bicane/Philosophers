/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:53:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 21:53:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	*one_philo_routine(void *ptr)
{
	(void)ptr;
	printf(YELLOW"%-6d"BLUE" 1"RESET " has taken a fork\n", 0);
	return (NULL);
}

void	one_philo(t_table *table)
{
	pthread_t	philo;

	pthread_create(&philo, NULL, one_philo_routine, NULL);
	ft_sleep(table->time_to_die, NULL);
	printf(YELLOW"%-6ld" BLUE" 1" RED" died\n"RESET, table->time_to_die);
	pthread_join(philo, NULL);
}

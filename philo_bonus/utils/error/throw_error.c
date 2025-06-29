/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:14:47 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/29 14:15:15 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_bonus.h"

void	parce_error_1(int error_mssg)
{
	if (1 == error_mssg)
		printf(RED"Error: Argument cannot be negative.\n"RESET);
	else if (2 == error_mssg)
		printf(RED"Error: Argument must be a number.\n"RESET);
	else if (3 == error_mssg)
	{
		printf(RED"Error: Argument is too large (greater than ");
		printf("INT_MAX).\n"RESET);
	}
	else if (4 == error_mssg)
	{
		printf(RED"Error: The number of philosophers must be at");
		printf("least 1.\n"RESET);
	}
	else if (5 == error_mssg)
		printf(RED"Error: Routine arguments must be greater than zero\n"RESET);
	else if (6 == error_mssg)
	{
		printf(RED"Error: Philosophers must eat at least once. Number of");
		printf("meals cannot be 0.\n"RESET);
	}
}

void	parce_error_2(int error_mssg)
{
	if (7 == error_mssg)
	{
		printf(RED"Error: Invalid number of arguments, arguments");
		printf("must be 5 or 6.\n"RESET YELLOW"Usage: ./philo n_philos");
		printf (" time_to_die time_to_eat time_to_sleep [n_of_time");
		printf("s_philos_must_eat]\n"RESET);
	}
}

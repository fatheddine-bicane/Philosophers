/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:10:27 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/24 17:12:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	parce_error_1(int error_mssg)
{
	if (1 == error_mssg)
	{
		printf(RED"Error: Argument cannot be negative.\n"RESET);
	}
	else if (2 == error_mssg)
	{
		printf(RED"Error: Argument must be a number.\n"RESET);
	}
	else if (3 == error_mssg)
	{
		printf(RED"Error: Argument is too large (greater than INT_MAX).\n"RESET);
	}
	else if (4 == error_mssg)
	{
		printf(RED"Error: The number of philosophers must be at least 1.\n"RESET);
	}
	else if (5 == error_mssg)
	{
		printf(RED"Error: Routine arguments must be greater than zero\n"RESET);
	}
	else if (6 == error_mssg)
	{
		printf(RED"Error: Philosophers must eat at least once. Number of meals cannot be 0.\n"RESET);
	}
}

void	init_error_1(int error_mssg)
{
	if (1 == error_mssg)
	{
		printf(RED"Error: pthread_mutex_init failed.\n"RESET);
	}
}

void	dinner_error_1(int	error_mssg)
{
	if (1 == error_mssg)
	{
		printf(RED"Error: pthread_create failed.\n"RESET);
	}
}

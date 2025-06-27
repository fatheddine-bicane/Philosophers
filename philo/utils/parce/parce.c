/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:26:52 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/27 17:48:06 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static bool	parce_nbr_philos(t_table *table, char *arg)
{
	table->philo_nbr = ft_atol(arg);
	if (-1 == table->philo_nbr)
		return (false);
	if (0 == table->philo_nbr)
		return (parce_error_1(4), false);
	return (true);
}

static bool	parce_philos_routine(t_table *table, char **argv)
{
	table->time_to_die = ft_atol(argv[2]);
	if (0 >= table->time_to_die)
		return (parce_error_1(5), false);
	/*table->time_to_die *= 1e3;*/
	table->time_to_eat = ft_atol(argv[3]);
	if (0 >= table->time_to_eat)
		return (parce_error_1(5), false);
	/*table->time_to_eat *= 1e3;*/
	table->time_to_sleep = ft_atol(argv[4]);
	if (0 >= table->time_to_sleep)
		return (parce_error_1(5), false);
	/*table->time_to_sleep *= 1e3;*/
	return (true);
}

static bool	parce_op_arg(t_table *table, char *arg, int argc)
{
	if (6 == argc)
	{
		table->limit_meals = ft_atol(arg);
		if (-1 == table->limit_meals)
			return (false);
		if (0 == table->limit_meals)
			return (parce_error_1(6), false);
	}
	else
		table->limit_meals = -1;
	return (true);
}

bool	parce_args(int argc, char **argv, t_table *table)
{
	if (false == parce_nbr_philos(table, argv[1]))
		return (false);
	if (false == parce_philos_routine(table, argv))
		return (false);
	if (false == parce_op_arg(table, argv[5], argc))
		return (false);
	return (true);
}

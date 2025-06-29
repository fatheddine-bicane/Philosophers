/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:55 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/28 22:13:39 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/*-------------------------------------------------------------------------*/
// INFO: if a function returns false in case of failure,
// a chain of false return will start, reaching main and
// returning 1 as error (malloc failed, one of pthread function faild, ...)
/*-------------------------------------------------------------------------*/

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		if (false == parce_args(argc, argv, &table))
			return (EXIT_FAILURE);
		if (false == data_init(&table))
			return (EXIT_FAILURE);
		dinner_simulation(&table);
		clean_up(&table);
		return (EXIT_SUCCESS);
	}
	else
	{
		parce_error_2(7);
		return (EXIT_FAILURE);
	}
}

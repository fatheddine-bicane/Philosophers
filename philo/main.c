/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:55 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/21 17:09:44 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		if (false == parce_args(argc, argv, &table))
			return (1);
		if (false == data_init(&table))
			return (1);
		/*printf("%ld\n", table.philo_nbr);*/
		/*printf("%ld\n", table.time_to_die);*/
		/*printf("%ld\n", table.time_to_eat);*/
		/*printf("%ld\n", table.time_to_sleep);*/
		/*printf("%ld\n", table.limit_meals);*/
	}
	else
		printf("sir fhalk\n");
}

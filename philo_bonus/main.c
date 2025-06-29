/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:12:54 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/29 15:50:20 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		if (false == parce_args(argc, argv, &table))
			return (EXIT_FAILURE);
		printf ("nadi\n");
	}
	else
	{
		parce_error_2(7);
		return (EXIT_FAILURE);
	}
}

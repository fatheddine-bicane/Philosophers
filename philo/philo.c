/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:34:06 by fbicane           #+#    #+#             */
/*   Updated: 2025/03/06 21:42:35 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_args(char **argv)
{
	int	a;
	int	i;

	a = 2;
	while (argv[a])
	{
		i = 0;
		while (argv[a][i])
		{
			if (!(argv[a][i] >= '0' && argv[a][i] <= '9'))
			{
				ft_throw_error_1(2);
			}
			i++;
		}
		a++;
	}
}

int	main(int argc, char **argv)
{
	/*if (argc == 6 || argc == 7)*/
	/*{*/
	/*	ft_check_args(argv);*/
	/*}*/
	/*else*/
	/*{*/
	/*	ft_throw_error_1(1);*/
	/*	return(0);*/
	/*}*/
}

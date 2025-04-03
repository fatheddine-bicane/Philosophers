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

void	ft_check_args(int argc, char **argv)
{
	args_t	*args;
	int	i = 1;

	args = malloc(sizeof(args_t));
	if (!args)
		return; //malloc protection
	while (i < 4)
	{
		if (ft_syntax_error(argv[i]))
			ft_throw_error_1(1, args);
	}
}

int	main(int argc, char **argv)
{
	printf("%lu", ULONG_MAX);
	/*pthread_t	tread1;*/
	/*if (argc == 5 || argc == 6)*/
	/*{*/
	/**/
	/*}*/
	/*else*/
	/*{*/
	/*	ft_throw_error_1(1);*/
	/*	return(0);*/
	/*}*/
}

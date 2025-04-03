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

void	ft_init_args(t_args **args, char **argv)
{
	(*args)->number_of_philos = ft_atol(argv[1]);
	if ((*args)->number_of_philos > UINT_MAX)
		ft_throw_error_1(3, *args);
	(*args)->time_to_die = ft_atol(argv[2]);
	if ((*args)->time_to_die > UINT_MAX)
		ft_throw_error_1(3, *args);
	(*args)->time_to_eat = ft_atol(argv[3]);
	if ((*args)->time_to_eat > UINT_MAX)
		ft_throw_error_1(3, *args);
	(*args)->time_to_sleep = ft_atol(argv[4]);
	if ((*args)->time_to_sleep > UINT_MAX)
		ft_throw_error_1(3, *args);
	if ((*args)->optional_argumen)
	{
		(*args)->meals_must_eat = ft_atol(argv[5]);
		if ((*args)->meals_must_eat > UINT_MAX)
			ft_throw_error_1(3, *args);
	}
}

void	ft_check_args(int argc, char **argv, t_args *args)
{
	int	i = 1;
	int	j = 5;

	args = malloc(sizeof(t_args));
	if (!args)
		return ;
	if (5 == argc)
		args->optional_argumen = false;
	else if (6 == argc)
		args->optional_argumen = true;
	if (6 == argc)
		j++;
	while (i < j)
	{
		if (ft_syntax_error(argv[i]))
			ft_throw_error_1(2, args);
		i++;
	}
	ft_init_args(&args, argv);
}

int	main(int argc, char **argv)
{
	t_args args;
	/*pthread_t	tread1;*/
	if (argc == 5 || argc == 6)
	{
		ft_check_args(argc, argv, &args);
		printf("Structure contents:\n"
		 "- number_of_philos: %u\n"
		 "- time_to_die: %u\n"
		 "- time_to_eat: %u\n"
		 "- time_to_sleep: %u\n"
		 "- meals_must_eat: %u\n"
		 "- optional_argumen: %s\n",
		 args.number_of_philos,
		 args.time_to_die,
		 args.time_to_eat,
		 args.time_to_sleep,
		 args.meals_must_eat,
		 args.optional_argumen ? "true" : "false");
	}
	else
	{
		ft_throw_error_1(1, NULL);
		return(0);
	}
}

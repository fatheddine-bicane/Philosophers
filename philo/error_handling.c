/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:15:17 by fbicane           #+#    #+#             */
/*   Updated: 2025/03/07 20:16:05 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(const char *err_mssg)
{
	int	i;

	i = -1;
	while (err_mssg[++i])
		write(2, &err_mssg[i], 1);
}

void	ft_throw_error_1(int error)
{
	if (error == 1)
	{
		ft_perror("error: invalid number of arguments\n");
	}
	else if (error == 2)
	{
		ft_perror("error: invalid argumment");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:37:49 by fbicane           #+#    #+#             */
/*   Updated: 2025/03/30 01:38:52 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_atol(const char *str)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		/*if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)*/
		/*	break ;*/
		i++;
	}
	return (res);
}

bool	ft_syntax_error(char *argv)
{
	if (!(*argv == '+' || (*argv >= '0' && *argv <= '9')))
		return (true);
	if ((argv[0] == '+') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (true);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (true);
	}
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:57:21 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/21 18:36:48 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || ' ' == c);
}

static inline bool	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

long	ft_atol(char *arg)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (is_space(arg[i]))
		i++;
	if ('-' == arg[i] || '+' == arg[i])
	{
		if ('+' == arg[i])
			i++;
		else
			return (parce_error_1(1), -1);
	}
	while (is_digit(arg[i]))
	{
		res = res * 10 + arg[i] - '0';
		if (res > INT_MAX)
			return (parce_error_1(3), -1);
		i++;
	}
	if (arg[i])
		return (parce_error_1(2), -1);
	return ((int)res);
}


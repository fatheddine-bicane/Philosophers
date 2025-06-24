/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:16 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/24 17:49:56 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	change_bool(t_mutex *mutex, bool *dest, bool value)
{
	if (0 != pthread_mutex_lock(mutex))
		return (false);
	*dest = value;
	if (0 != pthread_mutex_unlock(mutex))
		return (false);
	return (true);
}

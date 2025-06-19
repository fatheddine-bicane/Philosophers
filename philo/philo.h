/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:58 by fbicane           #+#    #+#             */
/*   Updated: 2025/06/18 16:46:43 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>

// INFO: colors
/*-----------------------------------------------*/
# ifndef BLUE
#  define BLUE  "\001\033[34m\002"
# endif
# ifndef GREEN
#  define GREEN "\001\033[32m\002"
# endif
# ifndef RED
#  define RED   "\001\033[31m\002"
# endif
# ifndef YELLOW
#  define YELLOW "\001\033[0;33m\002"
# endif
# ifndef RESET
#  define RESET "\001\033[0m\002"
# endif
/*-----------------------------------------------*/

#endif

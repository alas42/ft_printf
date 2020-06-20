/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:08:17 by avogt             #+#    #+#             */
/*   Updated: 2018/11/21 13:21:51 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	result_tmp;

	result_tmp = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\r' || *str == '\f')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		result_tmp = (result_tmp * 10) + (*str++ - '0');
	return (result_tmp * sign);
}

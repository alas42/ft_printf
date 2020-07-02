/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:11:41 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 15:14:19 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	is_min(char *string, t_tab *tab, char *arg, long int pos)
{
	long int c;
	long int i;
	long int len_arg;

	len_arg = ft_strlen(arg);
	c = 0;
	i = 0;
	if (arg[0] == '-')
	{
		if (tab->arg->flags[0])
		{
			string[0] = '-';
			return (len_arg - 1);
		}
		else
		{
			string[pos] = '-';
			return (len_arg - 1);
		}
	}
	return (len_arg);
}

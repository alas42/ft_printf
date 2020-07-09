/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:15:05 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:22:45 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*handle_c(t_tab *tab)
{
	char		c;

	c = (char)va_arg(tab->ap, int);
	if (tab->arg->width < 0)
	{
		tab->arg->width *= -1;
		tab->arg->flags[0] = 1;
	}
	if (tab->arg->flags[0])
		write(1, &c, 1);
	while (tab->arg->width - 1 > 0)
	{
		ft_putchar(' ');
		tab->arg->width--;
		tab->len += 1;
	}
	tab->len += 1;
	if (!tab->arg->flags[0])
		write(1, &c, 1);
	return (tab);
}

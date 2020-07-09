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

	i = -1;
	c = (char)va_arg(tab->ap, int);
	if (tab->convert[1] == '0' && tab->convert[0] != '-')
		display_gap(tab, '0', tab->arg->width - 1, 1);
	else if (tab->convert[0] != '-')
		display_gap(tab, ' ', tab->arg->width - 1, 1);
	tab->len += 1;
	write(1, &c, 1);
	if (tab->convert[0] == '-')
		display_char(tab, ' ', tab->arg->width - 1, 1);
	return (tab);
}

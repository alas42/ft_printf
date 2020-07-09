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
	if (tab->arg->flags[1] == '0' && tab->arg->flags[0] != '-')
		display_char(tab, '0', tab->arg->width - 1, 1);
	else if (tab->arg->flags[0] != '-')
		display_char(tab, ' ', tab->arg->width - 1, 1);
	tab->len += 1;
	write(1, &c, 1);
	if (tab->arg->flags[0] == '-')
		display_char(tab, ' ', tab->arg->width - 1, 1);
	return (tab);
}

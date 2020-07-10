/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:26:22 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 15:27:04 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*handle_percent(t_tab *tab)
{
	if (tab->arg->flags[1] && tab->arg->prec <= 0 && !tab->arg->flags[0])
	{
		tab->arg->prec = tab->arg->width;
		tab->arg->width = 0;
	}
	if (!tab->arg->flags[0])
		display_char(tab, ' ', tab->arg->width - 1, 1);
	if (tab->arg->flags[1])
		display_char(tab, '0', tab->arg->prec - 1, 1);
	write(1, "%", 1);
	if (!tab->arg->flags[0])
		display_char(tab, ' ', tab->arg->width - 1, 1);
	tab->len++;
	return (tab);
}

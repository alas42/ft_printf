/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:17:29 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 15:32:47 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_tab	*change_arg_prec(char *arg_to_print, t_tab *tab)
{
	if (tab->arg->flags[1] && tab->arg->prec == -1 && !tab->arg->flags[0])
	{
		tab->arg->prec = tab->arg->width;
		if (arg_to_print[0] == '-' || tab->arg->flags[0])
			tab->arg->prec--;
	}
	return (tab);
}

static t_tab	*get_string_d(char *arg_to_print, t_tab *tab, long int arg)
{
	long int	placed;
	long int	len_arg;

	len_arg = ft_strlen(arg_to_print);
	len_arg = (arg_to_print[0] == '-') ? len_arg - 1 : len_arg;
	arg = (arg < 0) ? arg * -1 : arg;
	change_arg_prec(arg_to_print, tab);
	placed = len_arg;
	if (len_arg <= tab->arg->prec && tab->arg->prec >= 0)
		placed = tab->arg->prec;
	if (arg_to_print[0] == '-')
		placed++;
	tab->len += (placed <= tab->arg->width) ? tab->arg->width : placed;
	if (!tab->arg->flags[0])
		display_char(tab, ' ', tab->arg->width - placed, 0);
	if (arg_to_print[0] == '-')
		write(1, &arg_to_print[0], 1);
	display_char(tab, '0', tab->arg->prec - len_arg, 0);
	ft_putnbr_l_fd(arg, 1);
	if (tab->arg->flags[0])
		display_char(tab, ' ', tab->arg->width - placed, 0);
	return (tab);
}

t_tab			*handle_d(t_tab *tab)
{
	long int	arg;
	char		*arg_to_print;
	size_t		len_to_print;

	len_to_print = 0;
	arg = (long int)va_arg(tab->ap, int);
	arg_to_print = ft_itoa(arg);
	if (arg == 0 && tab->arg->prec == 0)
	{
		display_char(tab, ' ', tab->arg->width, 1);
		return (tab);
	}
	get_string_d(arg_to_print, tab, arg);
	free(arg_to_print);
	return (tab);
}

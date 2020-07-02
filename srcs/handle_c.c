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
	char		*s;
	char		c;
	long int	i;

	i = -1;
	c = (char)va_arg(tab->ap, int);
	s = (tab->argument->field_width > 1) ?
		ft_strnew(tab->argument->field_width) : ft_strnew(1);
	if (!tab->argument->flags[0] && tab->argument->field_width > 1)
		while (++i < tab->argument->field_width - 1)
			s[i] = ' ';
	i = (i == -1) ? 0 : i;
	s[i] = c;
	if (tab->argument->flags[0] && tab->argument->field_width > 1)
		while (i++ < tab->argument->field_width - 1)
			s[i] = ' ';
	ft_putstr(s);
	free(s);
	return (tab);
}

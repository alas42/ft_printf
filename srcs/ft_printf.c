/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:43:31 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 16:49:20 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*set_arg(t_tab *tab)
{
	int i;

	i = -1;
	while (++i < 6)
		tab->argument.flags[i] = '\0';
	tab->argument.precision = -1;
	tab->argument.width = 0;
	tab->argument.specifier = '\0';
	return (tab);
}

t_tab	*set_tab(t_tab *tab)
{
	tab->i = 0;
	tab->len = 0;
	tab->specifiers = "csdiouxX";
	tab->flags = "+-#0 ";
	tab->f_copy = (char *)tab->format;
	return (tab);
}

int		parse_format(t_tab *tab)
{
	while (tab->f_copy[tab->i] == '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			tab->i++;
			set_arg(tab);
			parse_arg(tab);
		}
		else
		{
			write(1, &tab->f_copy[tab->i], 1);
			tab->len++;	
		}
		tab->i++;
	}
	return (tab->len)
}

int		ft_printf(const char *format, ...)
{
	t_tab	*tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab = set_tab(tab);
	if (format) 
	{
		va_start(tab->ap, format);
		tab->len = parse(tab);
		va_end(tab->ap);
	}
	free(tab);
	return (tab->len);
}

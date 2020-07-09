/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:10:42 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 19:20:12 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*check_flags(t_tab *tab)
{
	int			i;
	static char	flags[] = "-0\0";

	i = 0;
	while (flags[i] != '\0')
	{
		while (tab->f_diff[tab->i] == flags[i])
		{
			while (tab->f_diff[tab->i] == '-')
			{
				tab->arg->flags[0] = '-';
				tab->i++;
			}
			while (tab->f_diff[tab->i] == '0')
			{
				tab->arg->flags[1] = '0';
				tab->i++;
			}
			i = 0;
		}
		i++;
	}
	return (tab);
}

t_tab	*check_field_width(t_tab *tab)
{
	if (tab->f_diff[tab->i] == '*')
	{
		tab->arg->width = (long int)va_arg(tab->ap, int);
		tab->i++;
		if (tab->arg->width < 0)
		{
			tab->arg->width *= -1;
			tab->arg->flags[0] = 1;
		}
	}
	else if (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
	{
		while (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
		{
			tab->arg->width *= 10;
			tab->arg->width += (tab->f_diff[tab->i] - 48);
			tab->i++;
		}
	}
	return (tab);
}

t_tab	*check_precision(t_tab *tab)
{
	if (tab->f_diff[tab->i] == '.')
	{
		tab->i++;
		tab->arg->prec = 0;
		if (tab->f_diff[tab->i] == '*')
		{
			tab->arg->prec = (long int)va_arg(tab->ap, int);
			tab->arg->prec = (tab->arg->prec < -1) ? -1
				: tab->arg->prec;
			tab->i++;
		}
		else if (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
		{
			while (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
			{
				tab->arg->prec *= 10;
				tab->arg->prec += (tab->f_diff[tab->i] - 48);
				tab->i++;
			}
		}
		else
			tab->arg->prec = 0;
	}
	return (tab);
}

t_tab	*check_specifier(t_tab *tab)
{
	static char specifiers[] = "diuxXcsp%\0";
	int			i;

	i = 0;
	while (specifiers[i] != '\0')
	{
		if (specifiers[i] == tab->f_diff[tab->i])
		{
			tab->arg->specifier = specifiers[i];
			tab->arg->redirector = i;
		}
		i++;
	}
	return (tab);
}

int		parse_arg(t_tab *tab)
{
	check_flags(tab);
	check_field_width(tab);
	check_precision(tab);
	check_specifier(tab);
	redirect(tab);
	return (tab->len);
}

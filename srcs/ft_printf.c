/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:43:31 by avogt             #+#    #+#             */
/*   Updated: 2020/07/10 13:45:35 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*set_arg(t_tab *tab)
{
	int i;

	i = -1;
	if (!(tab->arg = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	while (++i < 2)
		tab->arg->flags[i] = 0;
	tab->arg->prec = -1;
	tab->arg->width = 0;
	tab->arg->specifier = '\0';
	tab->arg->redirector = -1;
	return (tab);
}

int		parse_format(t_tab *tab)
{
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			tab->i++;
			if (!(set_arg(tab)))
				exit(-1);
			parse_arg(tab);
		}
		else
		{
			write(1, &tab->f_copy[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}

int		ft_printf(const char *format, ...)
{
	t_tab	*tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab->i = 0;
	tab->len = 0;
	tab->arg = NULL;
	tab->f_copy = (char *)tab->format;
	tab->f_copy2 = (char *)tab->format;
	if (format)
	{
		va_start(tab->ap, format);
		tab->len = parse_format(tab);
		va_end(tab->ap);
	}
	free(tab->arg);
	free(tab);
	return (tab->len);
}

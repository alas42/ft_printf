/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:43:31 by avogt             #+#    #+#             */
/*   Updated: 2020/06/23 14:14:32 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*set_arg(t_tab *tab)
{
	int i;

	i = -1;
	if (!(tab->argument = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	while (++i < 6)
		tab->argument->flags[i] = '\0';
	tab->argument->precision = -1;
	tab->argument->field_width = 0;
	tab->argument->specifier = '\0';
	tab->argument->redirector = -1;
	/*
	 * printf("tab->argument->precision : %ld\ntab->argument->width : %ld\ntab->argument->specifier : %c\n",	tab->argument->precision, tab->argument->field_width, tab->argument->specifier);
	 */
	return (tab);
}

t_tab	*set_tab(t_tab *tab)
{
	tab->i = 0;
	tab->len = 0;
	tab->f_copy = (char *)tab->format;
	tab->f_diff = (char *)tab->format;
	/*
	 *
	 * printf("normally, everythings set in t_tab\nf_copy = %s\n", tab->f_copy);
	 */
	 return (tab);
}

int		parse_format(t_tab *tab)
{
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			/*
			 * printf("%% found\n");
			 */ 
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
	return (tab->len);
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
		/*
		 * printf("format good\n");
		 */
		va_start(tab->ap, format);
		tab->len = parse_format(tab);
		va_end(tab->ap);
	}
	free(tab);
	return (tab->len);
}

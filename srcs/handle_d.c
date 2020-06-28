/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:17:29 by avogt             #+#    #+#             */
/*   Updated: 2020/06/26 21:07:52 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_str_2(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int c;
	long int i;

	c = 0;
	i = 0;
	if (tab->argument->precision > len_arg)
		while (c++ < tab->argument->precision - len_arg)
			string[i++] = '0';
	c = 0;
	while (c < len_arg)
		string[i++] = arg[c++];
	c = 0;
	if (tab->argument->precision > len_arg)
	{
		if (tab->argument->field_width > tab->argument->precision)
			c = tab->argument->field_width - tab->argument->precision;
	}
	else
		if (tab->argument->field_width > len_arg)
			c = tab->argument->field_width - len_arg;
	while (c-- > 0)
		string[i++] = ' ';
	return (1);
}

static int	fill_str_1(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int	c;
	long int	i;

	i = 0;
	c = 0;
	if (!tab->argument->flags[0])
	{
		if (tab->argument->precision > len_arg)
		{
			if (tab->argument->field_width > tab->argument->precision)
				c = tab->argument->field_width - tab->argument->precision;
		}
		else
			if (tab->argument->field_width > len_arg)
				c = tab->argument->field_width - len_arg;
		while (c-- > 0)
			string[i++] = (tab->argument->flags[1]) ? '0' : ' ';
		c = 0;
		if (tab->argument->precision > len_arg)
			while (c++ < tab->argument->precision - len_arg)
				string[i++] = '0';
		c = 0;
		while (c < len_arg)
			string[i++] = arg[c++];
		return (1);
	}
	else
		return (fill_str_2(string, tab, arg, len_arg));
}

static char	*get_string_d(char *arg_to_print, t_tab *tab, int arg)
{
	char		*string;
	long int	len_arg;
	char		signe;

	signe = (arg < 0) ? '-' : '+';
	len_arg = (long int) ft_strlen(arg_to_print);
	len_arg = (signe == '-') ? len_arg -1 : len_arg;
	string = NULL;
	if (tab->argument->field_width >= tab->argument->precision
		&& tab->argument->field_width > len_arg)
		string = ft_strnew(tab->argument->field_width);
	else if (tab->argument->field_width < tab->argument->precision
		&& tab->argument->precision > len_arg)
		string = (signe == '-') ? ft_strnew(tab->argument->precision + 1)
			: ft_strnew(tab->argument->precision);
	else if (signe == '-')
		string = ft_strnew(len_arg + 1);
	else
		string = ft_strnew(len_arg);
	if (fill_str_1(string, tab, arg_to_print, (long int) ft_strlen(arg_to_print)))
		return (string);
	else
		return (NULL);
}

t_tab		*handle_d(t_tab *tab)
{
	int 		arg;
	char		*arg_to_print;
	char		*string;
	size_t		len_to_print;

	len_to_print = 0;
	arg = va_arg(tab->ap, int);
	arg_to_print = ft_itoa(arg);
	string = get_string_d(arg_to_print, tab, arg);
	if (string == NULL)
		exit (-1);
	len_to_print = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
	ft_strdel(&arg_to_print);
	return (tab);
}

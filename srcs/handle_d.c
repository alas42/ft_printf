/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:17:29 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:31:44 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	get_c(t_tab *tab, long int len_arg, char *arg)
{
	long int c;

	c = 0;
	if (tab->arg->prec > len_arg)
	{
		if (tab->arg->width > tab->arg->prec)
			c = (arg[0] == '-') ? tab->arg->width - (tab->arg->prec + 1)
				: tab->arg->width - tab->arg->prec;
	}
	else
	{
		if (tab->arg->width > len_arg)
			c = tab->arg->width - len_arg;
	}
	return (c);
}

static long int	is_min(char *string, t_tab *tab, char *arg, long int pos)
{
	long int c;
	long int i;
	long int len_arg;

	len_arg = ft_strlen(arg);
	c = 0;
	i = 0;
	if (arg[0] == '-')
	{
		if (tab->arg->flags[0])
		{
			string[0] = '-';
			return (len_arg - 1);
		}
		else
		{
			string[pos] = '-';
			return (len_arg - 1);
		}
	}
	return (len_arg);
}

static int		f_str_2(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int c;
	long int i;

	c = 0;
	i = (arg[0] == '-') ? 1 : 0;
	len_arg = is_min(string, tab, arg, i);
	if (tab->arg->prec > len_arg)
		while (c++ < tab->arg->prec - len_arg)
			string[i++] = '0';
	c = (arg[0] == '-') ? 1 : 0;
	while (arg[c] != '\0')
		string[i++] = arg[c++];
	c = 0;
	len_arg = (arg[0] == '-') ? len_arg + 1 : len_arg;
	c = get_c(tab, len_arg, arg);
	while (c-- > 0)
		string[i++] = ' ';
	return (1);
}

static int		f_str_1(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int	c;
	long int	i;

	i = 0;
	c = 0;
	if (!tab->arg->flags[0])
	{
		c = get_c(tab, len_arg, arg);
		while (c-- > 0)
			string[i++] = (tab->arg->flags[1]) ? '0' : ' ';
		c = 0;
		len_arg = is_min(string, tab, arg, i);
		i = (arg[0] == '-') ? i + 1 : i;
		if (tab->arg->prec > len_arg)
			while (c++ < tab->arg->prec - len_arg)
				string[i++] = '0';
		c = (arg[0] == '-') ? 1 : 0;
		while (arg[c] != '\0')
			string[i++] = arg[c++];
		return (1);
	}
	else
		return (f_str_2(string, tab, arg, len_arg));
}

static char		*get_string_d(char *arg_to_print, t_tab *tab, int arg)
{
	char		*string;
	long int	len_arg;
	char		signe;

	signe = (arg < 0) ? '-' : '+';
	len_arg = (long int)ft_strlen(arg_to_print);
	len_arg = (signe == '-') ? len_arg - 1 : len_arg;
	string = NULL;
	if (tab->arg->width >= tab->arg->prec
		&& tab->arg->width > len_arg)
		string = ft_strnew(tab->arg->width);
	else if (tab->arg->width < tab->arg->prec
		&& tab->arg->prec > len_arg)
		string = (signe == '-') ? ft_strnew(tab->arg->prec + 1)
			: ft_strnew(tab->arg->prec);
	else if (signe == '-')
		string = ft_strnew(len_arg + 1);
	else
		string = ft_strnew(len_arg);
	if (f_str_1(string, tab, arg_to_print, (long int)ft_strlen(arg_to_print)))
		return (string);
	return (NULL);
}

t_tab			*handle_d(t_tab *tab)
{
	int			arg;
	char		*arg_to_print;
	char		*string;
	size_t		len_to_print;

	len_to_print = 0;
	arg = va_arg(tab->ap, int);
	arg_to_print = ft_itoa(arg);
	string = get_string_d(arg_to_print, tab, arg);
	if (string == NULL)
		exit(-1);
	len_to_print = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
	ft_strdel(&arg_to_print);
	return (tab);
}

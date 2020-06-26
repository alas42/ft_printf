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

/*
 *static int fill_string2(char *string, t_tab *tab, char *arg, long int pos)
 *{
 *	return (1);
 *}
 */

static int fill_string(char *string, t_tab *tab, char *arg, char signe)
{
	long int	c;
	long int	i;
	long int	j;
	char		*result;

	i = 0;
	j = 0;
	c = 0;
	result = (signe == '-') ? ft_strsub(arg, 1, (long int) (ft_strlen(arg) - 1)) : ft_strdup(arg);
	if (!tab->argument->flags[0])
	{
		if (tab->argument->precision < (long int) ft_strlen(arg))
			c = (signe == '-') ? tab->argument->field_width - ((long int) ft_strlen(arg) + 1) : tab->argument->field_width - (long int) ft_strlen(arg);
		else
			c = (signe == '-') ? tab->argument->field_width - tab->argument->precision : tab->argument->field_width - tab->argument->precision;
		if (c > 0)
		{
			while (i < c)
			{
				if (tab->argument->flags[1] && tab->argument->precision == -1)
				{
					if (i == 0 && (signe == '-'))
					{
						string[i] = signe;
						j++;
					}
					else
						string[i] = '0';
				}
				else
					string[i] = ' ';
				i++;
			}
		}
	}
	if ((signe == '-') && j == 0)
	{
		string[i++] = signe;
		j++;
	}
	j = (c > 0) ? j + c : j;
	c = -1;
	while (++c < tab->argument->precision - (long int) ft_strlen(arg))
	{
		string[j + c] = '0';
		i++;
	}
	j = 0;
	while (j < (long int) ft_strlen(arg))
		string[i++] = result[j++];
	if (tab->argument->flags[0])
		if (tab->argument->field_width > (long int) ft_strlen(arg))
			while (i < tab->argument->field_width)
				string[i++] = ' ';
	ft_strdel(&result);
	return (1);
}

static char	*get_string_d(char *arg, t_tab *tab)
{
	char		*string;
	long int	len_arg;
	char		signe;

	signe = (arg < 0) ? '-' : '+';
	len_arg = (long int) ft_strlen(arg);
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
	return (string);
	if (fill_string(string, tab, arg, signe))
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
	if (!(string = get_string_d(arg_to_print, tab)))
		exit (-1);
	len_to_print = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
	ft_strdel(&arg_to_print);
	return (tab);
}

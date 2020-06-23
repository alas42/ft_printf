/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:19:33 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 16:20:02 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_string_2(char *string, t_tab *tab, char *arg, long int pos)
{
	long int	i;
	long int	j;
	long int	c;
	long int	len_arg;

	len_arg = (long int)ft_strlen(arg);
	i = pos;
	j = (i > 0 && tab->argument->precision > len_arg) ? i
		- (tab->argument->precision - len_arg) : 0;
	c = -1;
	while (++c < tab->argument->precision - len_arg)
	{
		string[j + c] = '0';
		i = (j == 0) ? i + 1 : i;
	}
	j = 0;
	while (j < len_arg)
		string[i++] = arg[j++];
	if (tab->argument->flags[0])
		if (tab->argument->field_width > len_arg)
			while (i < tab->argument->field_width)
				string[i++] = ' ';
	return (1);
}

static int	fill_string(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int i;

	i = 0;
	if (tab->argument->flags[0] == 0)
		if (tab->argument->field_width > len_arg
			&& tab->argument->field_width > tab->argument->precision)
			while (i < tab->argument->field_width - len_arg)
			{
				if (tab->argument->flags[1] && tab->argument->precision == -1)
					string[i] = '0';
				else
					string[i] = ' ';
				i++;
			}
	if (fill_string_2(string, tab, arg, i))
		return (1);
	return (-1);
}

static char	*get_string_x(char *arg, t_tab *tab, long int len_arg)
{
	char	*string;

	string = NULL;
	if (tab->argument->field_width >= tab->argument->precision
		&& tab->argument->field_width > len_arg)
		string = ft_strnew(tab->argument->field_width);
	else if (tab->argument->field_width < tab->argument->precision
		&& tab->argument->precision > len_arg)
		string = ft_strnew(tab->argument->precision);
	else
		string = ft_strnew(len_arg);
	if (fill_string(string, tab, arg, len_arg))
		return (string);
	else
		return (NULL);
}

t_tab	*handle_x(t_tab *tab)
{
	char	*arg_to_print;
	char	*s;
	size_t	len_to_print;

	len_to_print = 0;
	arg_to_print = ft_convert_base(va_arg(tab->ap, unsigned int), 16);
	printf("arg_to_print : --%s-- len_arg : --%ld-- field_width : --%ld-- precision : --%ld--\n", arg_to_print, (long int)ft_strlen(arg_to_print), tab->argument->field_width, tab->argument->precision);
	s = get_string_x(arg_to_print, tab, (long int)ft_strlen(arg_to_print));
	len_to_print = ft_strlen(s);
	s = (tab->argument->specifier == 'X') ? ft_toupper(s) : ft_tolower(s);
	ft_putstr(s);
	free(s);
	free(arg_to_print);
	return (tab);
}

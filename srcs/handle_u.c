/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:18:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 16:19:23 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_string_2(char *string, t_tab *tab, char *arg, size_t pos)
{
	size_t	i;
	size_t	j;
	int		c;
	size_t	len_arg;

	len_arg = ft_strlen(arg);
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

static int	fill_string(char *string, t_tab *tab, char *arg, size_t len_arg)
{
	size_t i;

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

static char	*get_string_u(char *arg, t_tab *tab, size_t len_arg)
{
	char	*string_to_print;

	s = NULL;
	if (tab->argument->field_width >= tab->argument->precision
		&& tab->argument->field_width > len_arg)
		s = ft_strnew(tab->argument->field_width);
	else if (tab->argument->field_width < tab->argument->precision
		&& tab->argument->precision > len_arg)
		s = ft_strnew(tab->argument->precision);
	else
		s = ft_strnew(len_arg);
	if (fill_string(string_to_print, tab, arg))
		return (string_to_print);
	else
		return (NULL);
}

t_tab		*handle_u(t_tab *tab)
{
	char	*arg_to_print;
	char	*s;
	size_t	len_to_print;

	len_to_print = 0;
	arg_to_print = ft_itoa(va_arg(tab->ap, unsigned int));
	s = get_string_u(arg_to_print, tab, ft_strlen(arg_to_print));
	len_to_print = ft_strlen(s);
	write(1, s, len_to_print);
	free(s);
	free(arg_to_print);
	return (tab);
}

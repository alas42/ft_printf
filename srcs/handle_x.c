/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:19:33 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:09:42 by avogt            ###   ########.fr       */
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
	j = (i > 0 && tab->arg->prec > len_arg) ? i
		- (tab->arg->prec - len_arg) : 0;
	c = -1;
	while (++c < tab->arg->prec - len_arg)
	{
		string[j + c] = '0';
		i = (j == 0) ? i + 1 : i;
	}
	j = 0;
	while (j < len_arg)
		string[i++] = arg[j++];
	if (tab->arg->flags[0])
		if (tab->arg->width > len_arg)
			while (i < tab->arg->width)
				string[i++] = ' ';
	return (1);
}

static int	fill_string(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int i;

	i = 0;
	if (tab->arg->flags[0] == 0)
		if (tab->arg->width > len_arg
			&& tab->arg->width > tab->arg->prec)
			while (i < tab->arg->width - len_arg)
			{
				if (tab->arg->flags[1] && tab->arg->prec == -1)
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
	if (tab->arg->width >= tab->arg->prec
		&& tab->arg->width > len_arg)
		string = ft_strnew(tab->arg->width);
	else if (tab->arg->width < tab->arg->prec
		&& tab->arg->prec > len_arg)
		string = ft_strnew(tab->arg->prec);
	else
		string = ft_strnew(len_arg);
	if (fill_string(string, tab, arg, len_arg))
		return (string);
	else
		return (NULL);
}

t_tab		*handle_x(t_tab *tab)
{
	char		*arg_to_print;
	char		*s;
	size_t		len_to_print;
	uintmax_t	num;

	len_to_print = 0;
	num = (unsigned int)(va_arg(tab->ap, unsigned int));
	arg_to_print = ft_convert_base(num, 16);
	if (num == 0 && tab->precision == 0)
	{
		display_char(tab, ' ', tab->arg->width, 1);
		return (tab);
	}
	s = get_string_x(arg_to_print, tab, (long int)ft_strlen(arg_to_print));
	len_to_print = ft_strlen(s);
	if (tab->arg->specifier == 'X')
		ft_strup(s);
	else
		ft_strlow(s);
	ft_putstr(s);
	tab->len += len_to_print;
	free(s);
	return (tab);
}

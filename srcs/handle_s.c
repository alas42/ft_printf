/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:15:42 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:49:45 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	get_length_s(long int length_copy_arg)
{
	long int prec;
	long int field_width;
	long int length_s;

	length_s = 0;
	prec = tab->argument->precision;
	field_width = tab->argument->field_width;
	if (prec < 0 ||
		prec >= length_copy_arg)
	{
		length_s = (field_width >= length_copy_arg)
			? field_width : length_copy_arg;
	}
	else
	{
		length_s = (field_width >= length_copy_arg)
			? field_width - (length_copy_arg - prec) : prec;
	}
	prec = (prec < 0 || prec >= length_copy_arg) ? length_copy_arg : prec;
	tab->argument->precision = prec;
	return (length_s);
}

t_tab		*handle_s(t_tab *tab)
{
	char		*s;
	long int	i;
	char		*copy_arg;
	long int	length_s;
	long int	length_copy_arg;

	i = -1;
	copy_arg = va_arg(tab->ap, char *);
	length_copy_arg = (long int)ft_strlen(copy_arg);
	length_s = get_length_s(length_copy_arg);
	copy_arg = (tab->argument->precision < length_copy_arg)
		? ft_strsub(copy_arg, 0, tab->argument->precision) : copy_arg;
	s = ft_strnew(length_s);
	if (!tab->argument->flags[0] && tab->argument->field_width > length_s)
		while (++i < tab->argument->field_width - length_s)
			s[i] = ' ';
	s = ft_strcat(s, copy_arg);
	if (tab->argument->flags[0] && tab->argument->field_width > length_s)
		while (++i < tab->argument->field_width - length_s)
			s[i] = ' ';
	ft_putstr(s);
	free(s);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:15:42 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 16:16:16 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*handle_s(t_tab *tab)
{
	char 		*s;
	long int	i;
	char		*copy_arg;
	long int	length_s;

	i = -1;
	copy_arg = va_arg(tab->ap, char *);
	if (tab->argument->precision < 0 ||
		tab->argument->precision >= ft_strlen(copy_arg))
		length_s = (tab->argument->field_width >= ft_strlen(copy_arg))
			? tab->argument->field_width : ft_strlen(copy_arg);
	else
		length_s = (tab->argument->field_width >= ft_strlen(copy_arg))
			? tab->argument->field_width - (ft_strlen(copy_arg) - tab->argument->precision): tab->argument->precision;
	tab->argument->precision = (tab->argument->precision < 0 || tab->argument->precision >= ft_strlen(copy_arg))
		? ft_strlen(copy_arg) : tab->argument->precision;
	copy_arg = (tab->argument->precision < ft_strlen(copy_arg)) ? ft_strsub(copy_arg, 0, tab->argument->precision) : copy_arg;
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
	free(copy_arg);
	return (tab);
}

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

t_tab	*handle_d(t_tab *tab)
{
	int 	num;
	char	*tmp_num;
	char	*s;
	char	*result;
	long int c;
	long int i;
	long int j;
	long int length_result;
	char	signe;

	num = va_arg(tab->ap, int);
	signe = (num < 0) ? '-' : '+';
	tmp_num = ft_itoa(num);
	length_result = ft_strlen(tmp_num);
	i = 0;
	j = 0;
	c = 0;
	result = (signe == '-') ? ft_strsub(tmp_num, 1, length_result - 1) : ft_strdup(tmp_num);
	ft_strdel(&tmp_num);
	length_result = (signe == '-') ? length_result -1 : length_result;
	if (tab->argument->field_width >= tab->argument->precision
		&& tab->argument->field_width > length_result)
		s = ft_strnew(tab->argument->field_width);
	else if (tab->argument->field_width < tab->argument->precision
		&& tab->argument->precision > length_result)
		s = (signe == '-') ? ft_strnew(tab->argument->precision + 1) : ft_strnew(tab->argument->precision);
	else if (signe == '-')
		s = ft_strnew(length_result + 1);
	else
		s = ft_strnew(length_result);
	if (!tab->argument->flags[0])
	{
		if (tab->argument->precision < length_result)
			c = (signe == '-') ? tab->argument->field_width - (length_result + 1) : tab->argument->field_width - length_result;
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
						s[i] = signe;
						j++;
					}
					else
						s[i] = '0';
				}
				else
					s[i] = ' ';
				i++;
			}
		}
	}
	if ((signe == '-') && j == 0)
	{
		s[i++] = signe;
		j++;
	}
	j = (c > 0) ? j + c : j;
	c = -1;
	while (++c < tab->argument->precision - length_result)
	{
		s[j + c] = '0';
		i++;
	}
	j = 0;
	while (j < length_result)
		s[i++] = result[j++];
	if (tab->argument->flags[0])
		if (tab->argument->field_width > length_result)
			while (i < tab->argument->field_width)
				s[i++] = ' ';
	ft_putstr(s);
	ft_strdel(&s);
	ft_strdel(&result);
	return (tab);
}

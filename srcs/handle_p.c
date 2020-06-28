/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:16:46 by avogt             #+#    #+#             */
/*   Updated: 2020/06/26 23:40:45 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_string2(char *string, char *arg, long int pos)
{
	long int i;
	long int j;
	long int len_arg;

	j = 0;
	len_arg = (long int)ft_strlen(arg);
	i = pos;
	while (j < len_arg)
		string[i++] = arg[j++];
	return (1);
}

static int	fill_string(char *string, t_tab *tab, char *arg, long int len_arg)
{
	long int i;
	long int j;

	j = 0;
	i = 0;
	if (tab->argument->flags[0])
	{
		string[i++] = '0';
		string[i++] = 'x';
	}
	else
	{
		if (tab->argument->field_width >= len_arg + 2)
			while (i < (tab->argument->field_width - (len_arg + 2)))
				string[i++] = ' ';
		string[i++] = '0';
		string[i++] = 'x';
	}
	if (fill_string2(string, arg, i))
		return (1);
	else
		return (-1);
}

char		*get_string_p(char *arg, t_tab *tab, long int len_arg)
{
	char	*string;

	string = NULL;
	if (tab->argument->field_width >= len_arg + 2)
		string = ft_strnew(tab->argument->field_width);
	else
		string = ft_strnew(len_arg + 2);
	if (fill_string(string, tab, arg, len_arg))
		return (string);
	return (NULL);
}

t_tab	*handle_p(t_tab *tab)
{
	char	*arg_to_print;
	char	*s;
	size_t	len_to_print;

	len_to_print = 0;
	arg_to_print = ft_convert_base_l((unsigned long int)va_arg(tab->ap, void *), 16);
	s = get_string_p(arg_to_print, tab, (long int)ft_strlen(arg_to_print));
	if(s == NULL)
		exit(-1);
	ft_strlow(s);
	len_to_print = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (tab);
}

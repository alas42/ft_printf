/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:16:46 by avogt             #+#    #+#             */
/*   Updated: 2020/07/09 15:30:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_tab		*display_string_u(t_tab *tab, char *str, int flag_min)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	tab->len += (not_blank <= tab->arg->width) ? tab->arg->width : not_blank;
	if (!flag_min)
		display_char(tab, ' ', tab->arg->width - not_blank, 0);
	write(1, "0x", 2);
	display_char(tab, '0', (tab->arg->prec - num_width) + 2, 1);
	ft_putstr(str);
	if (flag_min)
		display_char(tab, ' ', tab->arg->width - not_blank, 0);
	return (tab);
}

t_tab				*handle_p(t_tab *tab)
{
	char		*str;
	uintmax_t	num;
	int			flag_min;

	flag_min = 0;
	num = (unsigned long)(va_arg(tab->ap, unsigned long int));
	num = (uintmax_t)num;
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	if (tab->arg->flags[0])
		flag_min = 1;
	if (tab->arg->prec == 0 && num == 0)
		*str = '\0';
	if (tab->arg->flags[1] && tab->arg->prec == -1
			&& !tab->arg->flags[0])
	{
		tab->arg->prec = tab->arg->width - 2;
		tab->arg->width = 0;
	}
	display_string_u(tab, str, flag_min);
	free(str);
	return (tab);
}

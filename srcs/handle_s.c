/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:15:42 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 15:01:23 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*handle_s(t_tab *tab)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(tab->ap, char *);
	if (tab->arg->prec > -1 && s)
		s = ft_strndup(s, tab->arg->prec);
	else if (tab->arg->prec == -1 && s)
		s = ft_strdup(s);
	else if (tab->arg->prec > -1 && !s)
		s = ft_strndup("(null)", tab->arg->prec);
	else if (tab->arg->prec == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	if (tab->arg->flags[1] == '0' && tab->arg->flags[0] != '-')
		display_char(tab, '0', tab->arg->width - len, 1);
	else if (tab->arg->flags[0] != '-')
		display_char(tab, ' ', tab->arg->width - len, 1);
	ft_putstr(s);
	if (tab->arg->flags[0] == '-')
		display_char(tab, ' ', tab->arg->width - len, 1);
	free(s);
	return (tab);
}
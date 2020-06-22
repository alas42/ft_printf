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


t_tab	*handle_xlow(t_tab *tab)
{
	char	*arg_to_print;
	char	*s;

	s = NULL;
	arg_to_print = ft_convert_base(va_arg(tab->ap, unsigned int), 16);
	/*
	 * s = get_string_x(tab, arg_to_print);
	 */
	return (tab);
}

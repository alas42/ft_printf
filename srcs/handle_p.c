/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:16:46 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:27:23 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	ft_putstrprec(char *str, int prec)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar(str[char_count++]);
	return (char_count);
}

static int	ft_treat_width(int width, int minus, int has_zero)
{
	int char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

static int	ft_in_put_part_pointer(char *pointer, t_tab *tab)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (tab->arg->prec >= 0)
	{
		char_count += ft_treat_width(tab->arg->width, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, tab->arg->prec);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

t_tab		*handle_p(t_tab *tab)
{
	char				*pointer;
	int					char_count;
	unsigned long long	ull;

	ull = (unsigned long long)(va_arg(tab->ap, unsigned long long));
	char_count = 0;
	if (ull == 0 && tab->arg->prec == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(tab->arg->width, 0, 1));
	}
	pointer = ft_convert_base_ll(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)tab->arg->prec < ft_strlen(pointer))
		tab->arg->prec = ft_strlen(pointer);
	if (tab->arg->flags[0] == 1)
		char_count += ft_in_put_part_pointer(pointer, tab);
	char_count += ft_treat_width(tab->arg->width, ft_strlen(pointer) + 2, 0);
	if (tab->arg->flags[0] == 0)
		char_count += ft_in_put_part_pointer(pointer, tab);
	free(pointer);
	tab->len += char_count;
	return (tab);
}
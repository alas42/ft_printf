/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:43:31 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 16:49:20 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	check_format(format, ap);
	va_end(ap);
	return (1);
}

int		check_format(const char *format, va_list ap)
{
	unsigned int	i;
	unsigned int	length;
	int				length_subformat;
	char			*sub_format;

	i = 0;
	length_subformat = 0;
	length = ft_strlen(format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			sub_format = ft_strsub(format, i, length - i);
			length_subformat = check_string(sub_format, ap);
			if (length_subformat != -1)
				i += length_subformat;
			ft_strdel(&sub_format);
		}
		else
			ft_putchar(format[i++]);
	}
	return (1);
}

int		check_string(char *s, va_list ap)
{
	int			i;
	int			flags[2];
	int			attribut[2];
	int			conversion;

	i = 1;
	check_attribut(flags, s, &i);
	attribut[0] = check_champ(s, &i);
	attribut[1] = check_precision(s, &i);
	conversion = check_conversion(s, &i);
	if (conversion == -1)
		return (-1);
	ft_redirection(attribut, flags, conversion, ap);
	return (i);
}

int		ft_redirection(int *attr, int *flags, int type, va_list ap)
{
	char	*(*redirection[6])(int *flags, int champ, int prec, va_list ap);
	char	*piece_string;

	redirection[0] = ft_type_d;
	redirection[1] = ft_type_d;
	redirection[2] = ft_type_u;
	redirection[3] = ft_type_x;
	redirection[4] = ft_type_xmaj;
	redirection[5] = NULL;
	if (type == 0)
		piece_string = ft_type_c(flags, attr[0], ap);
	else if (type == 1)
		piece_string = ft_type_s(flags, attr[0], attr[1], ap);
	else if (type == 2)
		piece_string = ft_type_p(flags, attr[0], attr[1], ap);
	else
		piece_string = redirection[type - 3](flags, attr[0], attr[1], ap);
	if (piece_string)
	{
		ft_putstr(piece_string);
		return (ft_strlen(piece_string));
	}
	return (-1);
}

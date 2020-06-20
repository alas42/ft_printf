/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:14:14 by avogt             #+#    #+#             */
/*   Updated: 2020/06/20 14:04:06 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_c(int *attr, int champ, va_list ap)
{
	char	*s;
	char	c;
	int		i;

	i = -1;
	s = NULL;
	c = (char)va_arg(ap, int);
	s = (champ > 1) ? ft_strnew(champ) : ft_strnew(1);
	if (!attr[0] && champ > 1)
		while (++i < champ - 1)
			s[i] = ' ';
	i = (i == -1) ? 0 : i;
	s[i] = c;
	if (attr[0] && champ > 1)
		while (i++ < champ - 1)
			s[i] = ' ';
	/*
	 * printf("c = %c\nchamp = %d\nflags[0] (attr[0]) = %d\nflags[1] (attr[1]) = %d\ns = %s\nlenght s = %zu\n", c, champ, attr[0], attr[1], s, ft_strlen(s));
	 */
	 return (s);
}

char	*ft_type_s(int *attr, int champ, int prec, va_list ap)
{
	char	*s;
	char	*result;
	int		length_result;
	int		length_s;
	int		i;

	i = -1;
	result = NULL;
	s = va_arg(ap, char *);
	length_s = (!s) ? 0 : ft_strlen(s);
	if (prec < 0 || prec >= length_s)
		length_result = (champ >= length_s) ? champ : length_s;
	else
		length_result = (champ >= length_s) ? champ - (length_s - prec) : prec;
	prec = (prec < 0 || prec >= length_s) ? length_s : prec;
	s = (prec < length_s) ? ft_strsub(s, 0, prec) : s;
	result = ft_strnew(length_result);
	if (!attr[0] && champ > length_result)
		while (++i < champ - length_result)
			result[i] = ' ';
	result = ft_strcat(result, s);
	if (attr[0] && champ > length_result)
		while (++i < champ - length_result)
			result[i] = ' ';
	return (result);
}

char	*ft_type_p(int *attr, int champ, int prec, va_list ap)
{
	char				*s;
	char				*result;
	int					param[4];

	result = ft_convert_base_l((unsigned long int)va_arg(ap, void *), 16);
	param[0] = champ;
	param[1] = prec;
	param[2] = ft_strlen(result) + 2;
	param[3] = 0;
	s = get_string_p(param, attr, result);
	return (s);
}

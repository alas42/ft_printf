/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:09:53 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 14:51:20 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_type_x(int *attr, int champ, int prec, va_list ap)
{
	char	*s;
	char	*result;
	int		param[4];

	result = ft_convert_base(va_arg(ap, unsigned int), 16);
	param[0] = champ;
	param[1] = prec;
	param[2] = ft_strlen(result);
	param[3] = 0;
	s = get_string_x(param, attr, result);
	ft_strlow(s);
	return (s);
}

char		*ft_type_xmaj(int *attr, int champ, int prec, va_list ap)
{
	char	*s;
	char	*result;
	int		param[4];

	result = ft_convert_base(va_arg(ap, unsigned int), 16);
	param[0] = champ;
	param[1] = prec;
	param[2] = ft_strlen(result);
	param[3] = 0;
	s = get_string_x(param, attr, result);
	ft_strup(s);
	return (s);
}

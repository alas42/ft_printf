/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:40:18 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 15:11:14 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_type_u(int *attr, int champ, int prec, va_list ap)
{
	char	*s;
	char	*result;
	int		param[4];

	result = ft_itoa(va_arg(ap, unsigned int));
	param[0] = champ;
	param[1] = prec;
	param[2] = ft_strlen(result);
	param[3] = 0;
	s = get_string_u(param, attr, result);
	return (s);
}

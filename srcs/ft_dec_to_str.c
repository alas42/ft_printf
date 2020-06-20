/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:14:01 by avogt             #+#    #+#             */
/*   Updated: 2020/02/18 19:31:44 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_exposant(double d)
{
	int exp;

	exp = (int)d;
	return (exp);
}

static char	*ft_mantisse_str(int prec, double tmp)
{
	char	*mantisse;
	int		i;
	int		nombre_a_itoa;
	double	this_tmp;

	this_tmp = tmp;
	mantisse = ft_strnew(15);
	i = 0;
	while (i < prec)
	{
		tmp *= 10.0;
		nombre_a_itoa = (int)((this_tmp + 0.000001) - 10);
		mantisse[i] = nombre_a_itoa + '0';
		this_tmp = this_tmp - (double)(10 + (nombre_a_itoa - 1));
		i++;
	}
	mantisse[i] = '\0';
	return (mantisse);
}

static char	*ft_strcat_exp_man(char *itoa_d, char *man, size_t len)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (len + ft_strlen(man) + 2))))
		return (NULL);
	result = ft_strcpy(result, itoa_d);
	result[ft_strlen(result)] = '.';
	result = ft_strcat(result, man);
	return (result);
}

char		*ft_double_to_str(double d, int prec)
{
	char			*result;
	char			*man;
	char			*itoa_d;
	double			tmp;
	size_t			len;

	len = 0;
	tmp = d;
	while (tmp / 10 >= 1)
	{
		len++;
		tmp /= 10;
	}
	len++;
	itoa_d = ft_itoa(d);
	tmp = (d - (double)get_exposant(d)) + 1.0;
	prec = (prec == -1) ? 6 : prec;
	if (prec == 0)
		return (itoa_d);
	man = ft_mantisse_str(prec, tmp);
	result = ft_strcat_exp_man(itoa_d, man, len);
	return (result);
}

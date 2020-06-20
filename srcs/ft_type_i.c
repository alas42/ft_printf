/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:04:19 by avogt             #+#    #+#             */
/*   Updated: 2020/02/18 20:31:00 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_type_d(int *attr, int champ, int prec, va_list ap)
{
	int		        d;
	char			*s;
	char			*resultat;
	char			*result;
	int				c;
	int				i;
	int				j;
	int				length_result;
	char			signe;

	d = va_arg(ap, int);
	signe = (d < 0) ? '-' : '+';
	resultat = ft_itoa(d);
	length_result = ft_strlen(resultat);
	result = (signe == '-') ? ft_strsub(resultat, 1, length_result - 1) : ft_strdup(resultat);
	ft_strdel(&resultat);
	i = 0;
	j = 0;
	length_result = (signe == '-') ? length_result - 1 : length_result;
	if (champ >= prec && champ > length_result)
		s = ft_strnew(champ);
	else if (champ < prec && prec > length_result)
		s = (signe == '-') ? ft_strnew(prec + 1) : ft_strnew(prec);
	else if (signe == '-')
		s = ft_strnew(length_result + 1);
	else
		s = ft_strnew(length_result);
	c = 0;
	if (!attr[0])
	{
		if (prec < length_result)
			c = (signe == '-') ? champ - (length_result + 1) : champ - length_result;
		else
			c = (signe == '-') ? champ - (prec + 1) : champ - prec;
		if (c > 0)
			while (i < c)
			{
				if (attr[1] && prec == -1)
				{
					if (i == 0 && (signe == '-'))
					{
						s[i] = signe;
						j++;
					}
					else
						s[i] = '0';
				}
				else
					s[i] = ' ';
				i++;
			}
	}
	if ((signe == '-') && j == 0)
	{
		s[i++] = signe;
		j++;
	}
	j = (c > 0) ? j + c : j;
	c = -1;
	while (++c < prec - length_result)
	{
		s[j + c] = '0';
		i++;
	}
	j = 0;
	while (j < length_result)
		s[i++] = result[j++];
	if (attr[0])
		if (champ > length_result)
			while (i < champ)
				s[i++] = ' ';
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:52:48 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 13:02:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_prec(char const *s, int prec, int zero)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (!s)
		return ((void)0);
	len = ft_strlen(s);
	while (prec > len)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		prec--;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

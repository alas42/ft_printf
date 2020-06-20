/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:03:46 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 13:05:43 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_prec(int n, int prec, int zero)
{
	int		lengthn;
	char	*s;

	s = ft_itoa(n);
	lengthn = ft_strlen(s);
	if (prec < 0)
		prec = 0;
	if (prec == 0 && n == 0)
		write(1, "", 1);
	else
	{
		while (lengthn < prec)
		{
			if (zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			lengthn++;
		}
		ft_putnbr(n);
	}
	ft_strdel(&s);
}

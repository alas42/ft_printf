/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:26:49 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 13:06:11 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_l(long int n)
{
	if (n == LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_l(n * -1);
	}
	else
	{
		ft_putnbr_l(n / 10);
		ft_putnbr_l(n % 10);
	}
}

void	ft_putnbr_ll(long long int n)
{
	if (n == LLONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_ll(n * -1);
	}
	else
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
}

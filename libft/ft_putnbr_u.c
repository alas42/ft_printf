/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:40:22 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 13:02:43 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u(unsigned int u, int precision, int zero)
{
	if (u < 10)
		ft_putchar(u + 48);
	else
	{
		ft_putnbr_u(u / 10, precision, zero);
		ft_putnbr_u(u % 10, precision, zero);
	}
}

void	ft_putnbr_ull(unsigned long long int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_ull(n / 10);
		ft_putnbr_ull(n % 10);
	}
}

void	ft_putnbr_ul(unsigned long int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_ul(n / 10);
		ft_putnbr_ul(n % 10);
	}
}

void	ft_putnbr_uhh(unsigned char uc)
{
	if (uc < 10)
		ft_putchar(uc + 48);
	else
	{
		ft_putnbr_uhh(uc / 10);
		ft_putnbr_uhh(uc % 10);
	}
}

void	ft_putnbr_uh(unsigned short int uc)
{
	if (uc < 10)
		ft_putchar(uc + 48);
	else
	{
		ft_putnbr_uh(uc / 10);
		ft_putnbr_uh(uc % 10);
	}
}

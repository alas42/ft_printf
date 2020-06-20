/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:46:45 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 16:24:50 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(unsigned int n, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = representation[n % base];
		n /= base;
	}
	return (ptr);
}

char	*ft_convert_base_l(unsigned long int n, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = representation[n % base];
		n /= base;
	}
	return (ptr);
}

char	*ft_convert_base_ll(unsigned long long int n, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = representation[n % base];
		n /= base;
	}
	return (ptr);
}

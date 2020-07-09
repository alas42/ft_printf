/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:22:12 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 16:20:28 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		tmp;

	len = (n < 0) ? 2 : 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n == -2147483648)
		result[1] = '2';
	n = (n == -2147483648) ? 147483648 : n;
	n = (n < 0) ? n * -1 : n;
	result[len] = '\0';
	while (len--)
	{
		result[len] = ((n % 10) + '0');
		n /= 10;
		if (n == 0)
			return (result);
	}
	return (result);
}

char		*ft_itoa_l(long int n)
{
	char		*result;
	size_t		len;
	long int	tmp;

	len = (n < 0) ? 2 : 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n == LONG_MIN)
		result[1] = '9';
	n = (n == LONG_MIN) ? 223372036854775808 : n;
	n = (n < 0) ? n * -1 : n;
	result[len] = '\0';
	while (len--)
	{
		result[len] = ((n % 10) + '0');
		n /= 10;
		if (n == 0)
			return (result);
	}
	return (result);
}

char		*ft_itoa_ll(long long int n)
{
	char			*result;
	size_t			len;
	long long int	tmp;

	len = (n < 0) ? 2 : 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n == LONG_MIN)
		result[1] = '9';
	n = (n == LONG_MIN) ? 223372036854775808 : n;
	n = (n < 0) ? n * -1 : n;
	result[len] = '\0';
	while (len--)
	{
		result[len] = ((n % 10) + '0');
		n /= 10;
		if (n == 0)
			return (result);
	}
	return (result);
}

char		*ft_itoa_umax(uintmax_t	num)
{
	char		*result;
	size_t		len;
	uintmax_t	tmp;

	len = 1;
	tmp = n;
	while ((tmp /= 10) != 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = ((n % 10) + '0');
		n /= 10;
		if (n == 0)
			return (result);
	}
	return (result);
}
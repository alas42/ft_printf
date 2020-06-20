/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:06:27 by avogt             #+#    #+#             */
/*   Updated: 2019/09/16 13:08:08 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_u(unsigned int n)
{
	char			*result;
	size_t			len;
	unsigned int	tmp;

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

char		*ft_itoa_ul(unsigned long int n)
{
	char				*result;
	size_t				len;
	unsigned long int	tmp;

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

char		*ft_itoa_ull(unsigned long long int n)
{
	char					*result;
	size_t					len;
	unsigned long long int	tmp;

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

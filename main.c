/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/22 14:52:39 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c;
	unsigned int test;
	int champ;
	int precision;

	champ = 10;
	precision = 5;
	test = 30;
	c = 'l';
	ft_printf("%u\n", test);
	printf("%u\n", test);
	ft_printf("%30u\n", test);
	printf("%30u\n", test);
	ft_printf("%.5u\n", test);
	printf("%.5u\n", test);
	return (0);
}

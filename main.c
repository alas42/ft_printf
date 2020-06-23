/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/23 14:17:19 by avogt            ###   ########.fr       */
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
	ft_printf("%5u\n", test);
	printf("%5u\n", test);
	ft_printf("%.5u\n", test);
	printf("%.5u\n", test);
	ft_printf("%-5u\n", test);
	printf("%-5u\n", test);
	ft_printf("%05u\n", test);
	printf("%05u\n", test);
	
	return (0);
}

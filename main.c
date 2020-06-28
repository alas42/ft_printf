/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 16:36:52 by avogt             #+#    #+#             */
/*   Updated: 2020/06/28 16:08:46 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			*s;
	char			c;
	unsigned int	test;
	int 			champ;
	int 			precision;

	s = "Hello World, test!";
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
	
	ft_printf("%x\n", test);
	printf("%x\n", test);
	ft_printf("%5x\n", test);
	printf("%5x\n", test);
	ft_printf("%.5x\n", test);
	printf("%.5x\n", test);
	ft_printf("%-5x\n", test);
	printf("%-5x\n", test);
	ft_printf("%05x\n", test);
	printf("%05x\n", test);

	ft_printf("%X\n", test);
	printf("%X\n", test);
	ft_printf("%5X\n", test);
	printf("%5X\n", test);
	ft_printf("%.5X\n", test);
	printf("%.5X\n", test);
	ft_printf("%-5X\n", test);
	printf("%-5X\n", test);
	ft_printf("%05X\n", test);
	printf("%05X\n", test);

	ft_printf("%c\n", c);
	printf("%c\n", c);
	ft_printf("%5c\n", c);
	printf("%5c\n", c);
	ft_printf("%-5c\n", c);
	printf("%-5c\n", c);
	ft_printf("%-5c 0\n", c);
	printf("%-5c 0\n", c);
	ft_printf("%5c 45\n", c);
	printf("%5c 45\n", c);

	ft_printf("%s\n", s);
	printf("%s\n", s);
	ft_printf("%5s\n", s);
	printf("%5s\n", s);
	ft_printf("%-5s\n", s);
	printf("%-5s\n", s);
	ft_printf("%-s 0\n", s);
	printf("%-s 0\n", s);
	ft_printf("%.5s 45\n", s);
	printf("%.5s 45\n", s);
	
	ft_printf("%d\n", -333);
	printf("%d\n", -333);
	ft_printf("%5d\n", -333);
	printf("%5d\n", -333);
	ft_printf("%10.5d\n", -333);
	printf("%10.5d\n", -333);
	ft_printf("%-40d 0\n", -333);
	printf("%-40d 0\n", -333);
	ft_printf("%.10d 45\n", -333);
	printf("%.10d 45\n", -333);

	ft_printf("%p\n", &test);
	printf("%p\n", &test);
	ft_printf("%5p\n", &test);
	printf("%5p\n", &test);
	ft_printf("%-5p\n", &test);
	printf("%-5p\n", &test);
	ft_printf("%-p 0\n", &test);
	printf("%-p 0\n", &test);
	ft_printf("%45p 45\n", &test);
	printf("%45p 45\n", &test);
	
	return (0);
}

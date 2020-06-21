/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:03:26 by avogt             #+#    #+#             */
/*   Updated: 2020/06/21 14:06:33 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

/*
 * Using the same names (flags - specifiers etc) as the printf 
 * manual from tutorialspoint 
 * Flags are 0 - # + ' '
 * Specifiers are csdiouxX
 * Width and precision are self-explanatory
 *  
 * ap is the list of argument
 * len is the number of character that was printed -> will be the return value
 * i is the actual position on the virtual cursor as we process what 
 * is stored in format ans f_copy
 * 
 * f_copy is just a copy of format that i use to read
 */

typedef struct  s_arg
{
    char		flags[6];
    long int	field_width;
    long int	precision;
	char		specifier;
	short int	redirector;
}               t_arg;

typedef struct	s_tab
{
	const char  	*format;
	char	    	*f_copy;
	char	    	*f_diff;
	va_list			 ap;
	int		    	len;
	size_t	    	i;
	char			*specifiers;
	char			*flags;
    t_arg			*argument;    
}               t_tab;

int		ft_printf(const char *format, ...);
t_tab   *set_tab(t_tab *tab);
int     parse_fomat(t_tab *tab);
t_tab   *set_arg(t_tab *tab);
int     parse_arg(t_tab *tab);
t_tab	*check_flags(t_tab *tab);
t_tab	*check_field_width(t_tab *tab);
t_tab	*check_precision(t_tab *tab);
t_tab	*check_specifier(t_tab *tab);
t_tab	*handle_d(t_tab *tab);
t_tab	*handle_i(t_tab *tab);
t_tab	*handle_u(t_tab *tab);
t_tab	*handle_xlow(t_tab *tab);
t_tab	*handle_xup(t_tab *tab);
t_tab	*handle_c(t_tab *tab);
t_tab	*handle_s(t_tab *tab);
t_tab	*handle_p(t_tab *tab);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:03:26 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 16:16:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_printf2(const char *format, ...);
int		check_format(const char *format, va_list ap);
int		check_string(char *s, va_list ap);
void	check_attribut(int *flags, char *s, int *i);
int		check_precision(char *s, int *i);
int		check_champ(char *s, int *i);
int		check_conversion(char *s, int *i);
int		ft_redirection(int *attr, int *flags, int type, va_list ap);
char	*get_string_u(int *param, int *attr, char *result);
char	*get_string_p(int *param, int *attr, char *result);
char	*get_string_x(int *param, int *attr, char *result);
char	*ft_type_c(int *flags, int champ, va_list ap);
char	*ft_type_s(int *flags, int champ, int prec, va_list ap);
char	*ft_type_p(int *flags, int champ, int prec, va_list ap);
char	*ft_type_d(int *flags, int champ, int prec, va_list ap);
char	*ft_type_i(int *flags, int champ, int prec, va_list ap);
char	*ft_type_u(int *flags, int champ, int prec, va_list ap);
char	*ft_type_x(int *flags, int champ, int prec, va_list ap);
char	*ft_type_xmaj(int *flags, int champ, int prec, va_list ap);
char	*ft_double_to_str(double d, int prec);
#endif

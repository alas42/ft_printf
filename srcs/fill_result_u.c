/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_result_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:13:10 by avogt             #+#    #+#             */
/*   Updated: 2020/06/19 14:53:53 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_result2(int *param, int *attr, char *s, char *result)
{
	int i;
	int j;
	int c;

	i = param[3];
	j = (i > 0 && param[1] > param[2]) ? i - (param[1] - param[2]) : 0;
	c = -1;
	while (++c < param[1] - param[2])
	{
		s[j + c] = '0';
		i = (j == 0) ? i + 1 : i;
	}
	j = 0;
	while (j < param[2])
		s[i++] = result[j++];
	if (attr[0])
		if (param[0] > param[2])
			while (i < param[0])
				s[i++] = ' ';
	return (1);
}

static int	fill_result(int *param, int *attr, char *s, char *result)
{
	int	i;

	i = 0;
	if (attr[0] == 0)
		if (param[0] > param[2] && param[0] > param[1])
			while (i < param[0] - param[2])
			{
				if (attr[1] && param[1] == -1)
					s[i] = '0';
				else
					s[i] = ' ';
				i++;
			}
	param[3] = i;
	if (fill_result2(param, attr, s, result))
		return (1);
	else
		return (-1);
}

char		*get_string_u(int *param, int *attr, char *result)
{
	char	*s;

	s = NULL;
	if (param[0] >= param[1] && param[0] > param[2])
		s = ft_strnew(param[0]);
	else if (param[0] < param[1] && param[1] > param[2])
		s = ft_strnew(param[1]);
	else
		s = ft_strnew(param[2]);
	if (fill_result(param, attr, s, result))
		return (s);
	return (NULL);
}

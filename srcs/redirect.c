/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:37:07 by avogt             #+#    #+#             */
/*   Updated: 2020/07/02 14:39:20 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*redirect(t_tab *tab)
{
	t_tab	*(*redirection[10])(t_tab *tab);

	redirection[0] = handle_d;
	redirection[1] = handle_i;
	redirection[2] = handle_u;
	redirection[3] = handle_x;
	redirection[4] = handle_x;
	redirection[5] = handle_c;
	redirection[6] = handle_s;
	redirection[7] = handle_p;
	redirection[8] = handle_percent;
	redirection[9] = NULL;
	redirection[tab->arg->redirector](tab);
	return (tab);
}

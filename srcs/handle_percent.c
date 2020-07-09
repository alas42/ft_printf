#include "ft_printf.h"

t_tab   *handle_percent(t_tab *tab)
{
	if (tab->arg->flags[1] == '0' && tab->arg->prec <= 0 && !tab->arg->flags[0])
	{
		tab->arg->prec = tab->arg->width;
		tab->arg->width = 0;
	}
	if (tab->arg->flags[0] != '-')
		display_gap(tab, ' ', tab->arg->width - 1, 1);
	if (tab->arg->flags[1] == '0')
		display_gap(tab, '0', tab->arg->prec - 1, 1);
	write(1, "%", 1);
	if (tab->arg->flags[0] == '-')
		display_gap(tab, ' ', tab->arg->width - 1, 1);
	tab->len++;
	return (tab);
}
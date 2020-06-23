#include "ft_printf.h"

t_tab   *check_flags(t_tab *tab)
{
    int         i;
    static char flags[] = "-0\0";

    i = 0;
    while (flags[i] != '\0')
    {
        while (tab->f_diff[tab->i] == flags[i])
        {
            while (tab->f_diff[tab->i] == '-')
            {
                tab->argument->flags[0] = '-';
                tab->i++;
            }
            while (tab->f_diff[tab->i] == '0')
            {
                tab->argument->flags[1] = '0';  
                tab->i++;
            }
            i = 0;
        }
        i++;
    }
    return (tab);
}

t_tab   *check_field_width(t_tab *tab)
{
    if (tab->f_diff[tab->i] == '*')
    {
        tab->argument->field_width = (long int)va_arg(tab->ap, int);
        tab->i++;
    }
    else if (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
    {
        while (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
        {
            tab->argument->field_width *= 10;
            tab->argument->field_width += (tab->f_diff[tab->i] - 48);
            tab->i++;
        }
    }
    return (tab);
}

t_tab   *check_precision(t_tab *tab)
{
    if (tab->f_diff[tab->i] == '.')
    {
        tab->i++;
        tab->argument->precision = 0;
        if (tab->f_diff[tab->i] == '*')
        {
            tab->argument->precision = (long int)va_arg(tab->ap, int);
            tab->argument->precision = (tab->argument->precision < -1) ? -1 : tab->argument->precision;
            tab->i++;
        }
        else if (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
        {
            while (tab->f_diff[tab->i] >= '0' && tab->f_diff[tab->i] <= '9')
            {
                tab->argument->precision *= 10;
                tab->argument->precision += (tab->f_diff[tab->i] - 48);
                tab->i++;
            }
        }
        else
            tab->argument->precision = 0;
    }
    return (tab);
}

t_tab   *check_specifier(t_tab *tab)
{
    static char specifiers[] = "diuxXcsp\0";
    int         i;

    i = 0;
    while (specifiers[i] != '\0')
    {
        if (specifiers[i] == tab->f_diff[tab->i])
        {
            tab->argument->specifier = specifiers[i];
            tab->argument->redirector = i;
        }
        i++;
    }
    return (tab);
}

t_tab   *redirect(t_tab *tab)
{
    t_tab	*(*redirection[9])(t_tab *tab);

	redirection[0] = handle_d;
	redirection[1] = handle_i;
	redirection[2] = handle_u;
	redirection[3] = handle_x;
	redirection[4] = handle_x;
    redirection[5] = handle_c;
    redirection[6] = handle_s;
    redirection[7] = handle_p;
	redirection[8] = NULL;
    redirection[tab->argument->redirector](tab);
    return (tab);
}

int     parse_arg(t_tab *tab)
{
    check_flags(tab);
    check_field_width(tab);
    check_precision(tab);
    check_specifier(tab);
    redirect(tab);
    return (tab->len);
}

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
            while (flags[i] == '-')
            {
                tab->argument->flags[0] = '-';
                tab->i++;
            }
            while (flags[i] == '0')
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

    return (tab);
}

t_tab   *check_precision(t_tab *tab)
{

    return (tab);
}

t_tab   *check_specifier(t_tab *tab)
{
    static char specifiers[] = "csdiuxX\0";
    int         i;

    i = 0;
    while (specifiers[i] != '\0')
        i++;
    return (tab);
}

t_tab   *redirect(t_tab *tab)
{
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
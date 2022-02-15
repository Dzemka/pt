#include "../../push_swap.h"

static int  ft_check_double(t_list *list, int n)
{
    t_list  *elem;

    elem = list;
    while (elem)
    {
        if (*(int *)elem->content == n)
        {
            return (1);
        }
        elem = elem->next;
    }
    return (0);
}

static int ft_check_errors(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if(!ft_isdigit(str[i]) && str[i] != ' ')
            return (1);
        i++;
    }
    return (0);
}

static int  ft_get_val(char *str, t_list **list)
{
    char **values;
    t_list *elem;
    int i;
    int *val;

    elem = *list;
    i = 0;
    if(ft_check_errors(str))
        return (0);
    values = ft_split(str, ' ');
    i = 0;
    while(values[i])
    {
        val = (int *)malloc(sizeof (int *));
        *val = ft_atoi(values[i]);
        free(values[i]);
        elem = ft_lstnew(val);
        if (!elem || ft_check_double(*list, *val))
            return (0);
        ft_lstadd_back(list, elem);
        i++;
    }
    free(values);
    return (1);
}
int ft_fill_stack(int argc, char **argv, t_list **a)
{
    int i;

    i = 1;
    while(i < argc)
    {
        if(!ft_get_val(argv[i], a))
            return (0);
        i++;
    }
    if (ft_lstsize(*a) >= 2)
        return (1);
    else
        return (0);
}
#include "../../push_swap.h"

static int  ft_check_double(t_list *list, int n)
{
    t_list  *temp;

    temp = list;
    while (temp)
    {
        if (((t_elem *)temp->content)->val == n)
        {
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}

static  t_elem *ft_new_elem(int n)
{
    t_elem *elem;

    elem = (t_elem *) malloc(sizeof (t_elem));
    if(!elem)
        return (NULL);
    elem->val = n;
    return (elem);
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
    t_elem *temp_elem;
    t_list *temp_list;
    int i;

    temp_list = *list;
    i = 0;
    if(ft_check_errors(str))
        return (0);
    values = ft_split(str, ' ');
    i = 0;
    while(values[i])
    {
        temp_elem = ft_new_elem(ft_atoi(values[i]));
        temp_list = ft_lstnew(temp_elem);
        if (!temp_list || !temp_elem || ft_check_double(*list, temp_elem->val))
            return (0);
        ft_lstadd_back(list, temp_list);
        i++;
    }
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
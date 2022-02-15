#include "../../push_swap.h"

int ft_check_sort(t_list *list)
{
    t_list  *elem;

    elem = list;
    while (elem->next)
    {
        if (ELEM_VAL > *(int *)elem->next->content)
            return (0);
        elem = elem->next;
    }
    return (1);
}
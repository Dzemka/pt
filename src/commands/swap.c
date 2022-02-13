#include "../../push_swap.h"


static void    swap(t_list **list)
{
    t_list *elem;

    elem = *list;
    elem = elem->next;
    (*list)->next = (*list)->next->next;
    elem->next = (*list);
    (*list) = elem;
}

int sa(t_list **a, t_list **res)
{
    t_list *elem;
    char *str;

    swap(a);
    str = ft_strdup("sa\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

int sb(t_list **b, t_list **res)
{
    t_list *elem;
    char    *str;

    swap(b);
    str = ft_strdup("sb\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

int ss(t_list **a, t_list **b, t_list **res)
{
    t_list *elem;
    char    *str;

    swap(a);
    swap(b);
    str = ft_strdup("ss\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}
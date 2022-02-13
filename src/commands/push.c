#include "../../push_swap.h"

void    push(t_list **src, t_list **dst)
{
    t_list  *elem;

    elem = (*src)->next;
    (*src)->next = (*dst);
    *dst = *src;
    *src = elem;
}

int pa(t_list **a, t_list **b, t_list **res)
{
    t_list *elem;
    char *str;

    push(b, a);
    str = ft_strdup("pa\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return(0);
    ft_lstadd_back(res, elem);
    return (1);
}

int pb(t_list **b, t_list **a, t_list **res)
{
    t_list *elem;
    char *str;

    push(a, b);
    str = ft_strdup("pb\n");
    elem = ft_lstnew(str);
    if(!elem|| !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

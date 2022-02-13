#include "../../push_swap.h"

static  void    reverse_rotate(t_list **list)
{
    t_list *elem;
    t_list  *temp;

    elem = ft_lstlast(*list);
    temp = *list;
    while(temp->next != elem)
        temp = temp->next;
    temp->next = NULL;
    ft_lstadd_front(list, elem);
}

int rra(t_list **a, t_list **res)
{
    t_list *elem;
    char    *str;

    reverse_rotate(a);
    str = ft_strdup("rra\n");
    elem = ft_lstnew(str);
    if(!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

int rrb(t_list **b, t_list **res)
{
    t_list *elem;
    char *str;

    reverse_rotate(b);
    str = ft_strdup("rrb\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}
int rrr(t_list **a, t_list **b, t_list **res)
{
    t_list *elem;
    char *str;

    reverse_rotate(a);
    reverse_rotate(b);
    str = ft_strdup("rrr\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}
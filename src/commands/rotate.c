#include "../../push_swap.h"

static void rotate(t_list **list)
{
    t_list  *elem;

    elem = *list;
    ft_lstadd_back(list, elem);
    *list = (*list)->next;
    elem->next = NULL;
}
int ra(t_list **a, t_list **res)
{
    t_list *elem;
    char *str;

    rotate(a);
    str = ft_strdup("ra\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

int rb(t_list **b, t_list **res)
{
    t_list *elem;
    char    *str;

    rotate(b);
    str = ft_strdup("rb\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}

int rr(t_list **a, t_list **b, t_list **res) {
    t_list *elem;
    char *str;

    rotate(a);
    rotate(b);
    str = ft_strdup("rr\n");
    elem = ft_lstnew(str);
    if (!elem || !str)
        return (0);
    ft_lstadd_back(res, elem);
    return (1);
}
#include "../../push_swap.h"

static void rotate(t_list **list)
{
    t_list  *elem;

    elem = *list;
    ft_lstadd_back(list, elem);
    *list = (*list)->next;
    elem->next = NULL;
}
void    ra(t_list **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_list **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_list **a, t_list **b)
{

    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}
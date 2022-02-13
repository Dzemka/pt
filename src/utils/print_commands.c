#include "../../push_swap.h"

void    ft_print_cmnds(t_list *res)
{
    t_list *elem;
    t_list *temp;

    elem = res;
    while (elem)
    {
        if(elem->next)
        {
            if (!ft_strncmp(elem->content, "ra", 2))
            {
                if (!ft_strncmp(elem->next->content, "rb", 2))
                {
                    ft_strlcpy(elem->content, "rr\n", 4);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
            else if (!ft_strncmp(elem->content, "rb", 2))
            {
                if (!ft_strncmp(elem->next->content, "ra", 2))
                {
                    ft_strlcpy(elem->content, "rr\n", 4);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
            else if (!ft_strncmp(elem->content, "rra", 3))
            {
                if (!ft_strncmp(elem->next->content, "rrb", 3))
                {
                    ft_strlcpy(elem->content, "rrr\n", 5);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
            else if (!ft_strncmp(elem->content, "rrb", 3))
            {
                if (!ft_strncmp(elem->next->content, "rra", 3))
                {
                    ft_strlcpy(elem->content, "rrr\n", 5);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
            else if (!ft_strncmp(elem->content, "sa", 2))
            {
                if (!ft_strncmp(elem->next->content, "sb", 2))
                {
                    ft_strlcpy(elem->content, "ss\n", 4);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
            else if (!ft_strncmp(elem->content, "sb", 2))
            {
                if (!ft_strncmp(elem->next->content, "sa", 2))
                {
                    ft_strlcpy(elem->content, "ss\n", 4);
                    temp = elem->next;
                    elem->next = elem->next->next;
                    ft_lstdelone(temp, free);
                }
            }
        }
        ft_putstr_fd(elem->content, 1);
        elem = elem->next;
    }
}
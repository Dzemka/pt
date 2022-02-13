#include "../../push_swap.h"

void    ft_define_order(t_list *list)
{
    t_list  *elem;
    t_list  *temp;
    int pos;

    elem = list;
    while (elem)
    {
        temp = list;
        pos = 1;
        while(temp)
        {
            if (((t_elem *)elem->content)->val > ((t_elem *)temp->content)->val)
                pos++;
            temp = temp ->next;
        }
        ((t_elem *)elem->content)->pos_order = pos;
        elem = elem->next;
    }
}

int ft_check_sort(t_list *list)
{
    t_list  *elem;

    elem = list;
    while (elem->next)
    {
        if (((t_elem *)(elem->content))->pos_order + 1 != ((t_elem *)(elem->next->content))->pos_order)
            return (0);
        elem = elem->next;
    }
    return (1);
}

int ft_count_same_flags(t_list *list)
{
    t_list *elem;
    int max_flag;
    int count;

    elem = list;
    max_flag = ((t_elem *)elem->content)->flag;
    count = 0;
    while (elem)
    {
        if (((t_elem *)elem->content)->flag == max_flag)
            count++;
        elem = elem->next;
    }
    return (count);
}

void    ft_translate(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *a;
    while (temp)
    {
        printf("a-N:%d ", (((t_elem *) temp->content)->val));
        printf("a-P:%d ", ((t_elem *) temp->content)->pos_order);
        printf("a-F:%d ", ((t_elem *) temp->content)->flag);
        temp = temp->next;
        printf("\n");
    }
    printf("\n");
    temp = *b;
    while (temp)
    {
        printf("B-N:%d ", (((t_elem *) temp->content)->val));
        printf("B-P:%d ", ((t_elem *) temp->content)->pos_order);
        printf("B-F:%d ", ((t_elem *) temp->content)->flag);
        temp = temp->next;
        printf("\n");
    }
    printf("\n");
}
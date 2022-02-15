#include "../push_swap.h"

void    ft_sort_3_a(t_list **list)
{
    int a;
    int b;
    int c;

    a = *(int *)(*list)->content;
    b = *(int *)(*list)->next->content;
    c = *(int *)(*list)->next->next->content;

    if (c > b && b > a)
        return;
    if ((a > b && b > c) || (b > c && c > a))
    {
        sa(list);
        ft_sort_3_a(list);
    }
    if (c > a && a > b)
            sa(list);
    if (a > c && c > b)
            ra(list);
    if (b > a && a > c)
            rra(list);
}

void    ft_push_b(t_list **a, t_list **b, int min, int med, int max)
{
    int temp;

    temp = ft_lstsize(*a);
    while (temp)
    {
        if(A_VAL == max || A_VAL == med || A_VAL == min)
            ra(a);
        else
            pb(b, a);
        temp--;
    }
}

int ft_count_rotate_a(t_list **a, int val, int med)
{
    int     count_rotate;
    t_list  *elem;
    int     last_pos;

    count_rotate = 1;
    elem = *a;
    last_pos = *(int *) ft_lstlast(*a);
    if(val < ELEM_VAL && val > last_pos)
    {
//        if (last_pos >= med || A_VAL <= med)
        return (0);
    }
    (void)med;
    while (elem->next)
    {
        if (val > ELEM_VAL && val < *(int *)elem->next->content)
            break;
        count_rotate++;
        elem = elem->next;
    }
    return (count_rotate);
}

void    ft_init_moves(t_moves *moves)
{
    moves->ra = 0;
    moves->rb = 0;
    moves->rr = 0;
    moves->rra = 0;
    moves->rrb = 0;
    moves->rrr = 0;
    moves->ra_rrb = 0;
    moves->rb_rra = 0;
    moves->ra_rb_rr = 0;
    moves->rra_rrb_rrr = 0;
}

int ft_define_min_moves(t_moves *moves)
{
    int min;
    int temp_ra;
    int temp_rb;

    moves->ra_rrb = moves->ra + moves->rrb;
    moves->rb_rra = moves->rb + moves->rra;
    temp_ra = moves->ra;
    temp_rb = moves->rb;
    while (temp_ra && temp_rb)
    {
        temp_ra--;
        temp_rb--;
        moves->rr++;
    }
    moves->ra_rb_rr = moves->rr + temp_ra + temp_rb;
    temp_ra = moves->rra;
    temp_rb = moves->rrb;
    while (temp_ra && temp_rb)
    {
        temp_ra--;
        temp_rb--;
        moves->rrr++;
    }
    moves->rra_rrb_rrr = moves->rrr + temp_ra + temp_rb;
    min = moves->ra_rrb;
    if (moves->rb_rra < min)
        min = moves->rb_rra;
    if(moves->ra_rb_rr < min)
        min = moves->ra_rb_rr;
    if(moves->rra_rrb_rrr < min)
        min = moves->rra_rrb_rrr;
    return (min);
}

int ft_count_move(t_list **a, t_list **b, t_list *elem, t_moves *moves, int med)
{
    int count;
    int size_b;
    int size_a;

    ft_init_moves(moves);
    size_b = ft_lstsize(*b);
    size_a = ft_lstsize(*a);
    moves->rb = size_b - ft_lstsize(elem);
    moves->rrb = size_b - moves->rb;
    if (size_b == 1)
        moves->rrb = moves->rb + 1;
    count = ft_count_rotate_a(a, ELEM_VAL, med);
    moves->ra = count;
    moves->rra = size_a - count;
    count = ft_define_min_moves(moves);
    return (count);
}

t_list *ft_select_el(t_list **a, t_list **b, t_moves *moves, int med)
{
    t_list *elem;
    int count_move;
    int min_count;
    t_list *min_elem;

    elem = *b;
    min_count = ft_count_move(a, b, elem, moves, med);
    min_elem = elem;
    elem = elem->next;
    while (elem)
    {
        count_move = ft_count_move(a, b, elem, moves, med);
        if (count_move < min_count)
        {
            min_count = count_move;
            min_elem = elem;
        }
        elem = elem->next;
    }
    return (min_elem);
}

int ft_push_a(t_list **a, t_list **b, int med)
{
    t_list *elem;
    t_moves *moves;
    int count;

    if (!*b)
        return (1);
    moves = malloc(sizeof(t_moves));
    if(!moves)
        return (0);
    elem = ft_select_el(a, b, moves, med);
    count = ft_count_move(a, b, elem, moves, med);
    if (moves->ra_rb_rr == count)
    {
        while (moves->rr)
        {
            rr(a, b);
            moves->ra--;
            moves->rb--;
            moves->rr--;
        }
        while (moves->ra)
        {
            ra(a);
            moves->ra--;
        }
        while (moves->rb)
        {
            rb(b);
            moves->rb--;
        }
    }
    else if (moves->rra_rrb_rrr == count)
    {
        while (moves->rrr)
        {
            moves->rra--;
            moves->rrb--;
            moves->rrr--;
            rrr(a, b);
        }
        while (moves->rra)
        {
            rra(a);
            moves->rra--;
        }
        while (moves->rrb)
        {
            rrb(b);
            moves->rrb--;
        }
    }
    else if (moves->ra_rrb == count)
    {
        while (moves->ra)
        {
            ra(a);
            moves->ra--;
        }
        while (moves->rrb)
        {
            rrb(b);
            moves->rrb--;
        }
    }
    else if (moves->rb_rra == count)
    {
        while (moves->rra)
        {
            rra(a);
            moves->rra--;
        }
        while (moves->rb)
        {
            rb(b);
            moves->rb--;
        }
    }
    pa(a, b);
    ft_push_a(a, b, med);
    return (1);
}

void    ft_define_border(t_list *a, int *min, int *med, int *max)
{
    int size;
    t_list *elem;
    t_list *temp;
    int temp_size;

    elem = a;
    size = ft_lstsize(a);
    while (elem)
    {
        temp_size = size;
        temp = a;
        while (temp)
        {
            if (*(int *)elem->content > *(int *)temp->content)
                temp_size--;
            temp = temp->next;
        }
        if (temp_size == size / 2)
            *med = *(int *)elem->content;
        if (temp_size == size)
            *min = *(int *)elem->content;
        if (temp_size == 1)
            *max = *(int *)elem->content;
        elem = elem->next;
    }
}

void    ft_final_sort(t_list **a, int min)
{
    t_list *elem;
    int size_a;
    int count_rotate;

    elem = *a;
    count_rotate = 0;
    size_a = ft_lstsize(*a);
    while (ELEM_VAL != min)
    {
        count_rotate++;
        elem = elem->next;
    }
    if (size_a / 2 > count_rotate)
    {
        while (count_rotate)
        {
            ra(a);
            count_rotate--;
        }
    }
    else
    {
        count_rotate = size_a - count_rotate;
        while (count_rotate)
        {
            rra(a);
            count_rotate--;
        }
    }
}

int ft_sorting(t_list **a, t_list **b)
{
    int min;
    int med;
    int max;

    min = 0;
    med = 0;
    max = 0;
    ft_define_border(*a, &min, &med, &max);
    ft_push_b(a, b, min, med, max);
    ft_sort_3_a(a);
    if (!ft_push_a(a, b, med))
        return (0);
    ft_final_sort(a, min);
    return (1);
}

int ft_push_swap(t_list **a, t_list **b)
{
    if (ft_check_sort(*a))
        return (1);
    else if (ft_lstsize(*a) == 3)
        ft_sort_3_a(a);
    else if (!ft_sorting(a, b))
            return (0);
    return (1);
}
#include "../push_swap.h"

int ft_sort_3(t_list **list, t_list **res, int select)
{
    int a;
    int b;
    int c;

    a = ((t_elem *)(*list)->content)->pos_order;
    b = ((t_elem *)(*list)->next->content)->pos_order;
    c = ((t_elem *)(*list)->next->next->content)->pos_order;

    if (c > b && b > a)
        return (1);
    if ((a > b && b > c) || (b > c && c > a))
    {
        if (select == 1)
            sa(list, res);
        else
            sb(list, res);
    }
    a = ((t_elem *)(*list)->content)->pos_order;
    b = ((t_elem *)(*list)->next->content)->pos_order;
    c = ((t_elem *)(*list)->next->next->content)->pos_order;
    if (c > a && a > b)
    {
        if(select == 1)
        {
            sa(list, res);
        }
        else
        {
            sb(list, res);
        }
    }
    if (a > c && c > b)
    {
        if (select == 1)
            ra(list, res);
        else
            rb(list, res);
    }
    if (b > a && a > c)
    {
        if (select == 1)
            rra(list, res);
        else
            rrb(list, res);
    }
    return (1);
}

int ft_push_b(t_list **a, t_list **b, t_list **res, int max, int mid)
{
    int temp;

    temp = max;
    while (temp)
    {
        if(A_POS_ORDER == max || A_POS_ORDER == mid || A_POS_ORDER == 1)
        {
            if(!ra(a, res))
                return (0);
        }
        else
        {
            if(!pb(b, a, res))
                return (0);
        }
        temp--;
    }
    return (1);
}

int ft_count_rotate_a(t_list **a, int pos, int mid)
{
    int     count_rotate;
    t_list  *elem;
    int     last_pos;

    last_pos = ((t_elem *) ft_lstlast(*a)->content)->pos_order;
    count_rotate = 1;
    elem = *a;
    if(pos < ((t_elem *)(elem->content))->pos_order && pos > last_pos)
    {
        if (last_pos >= mid || A_POS_ORDER <= mid)
            return (0);
    }
    while (elem->next)
    {
        if (pos > ((t_elem *)(elem->content))->pos_order && pos < ((t_elem *)(elem->next->content))->pos_order)
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
    moves->ra_rr = moves->rr + temp_ra + temp_rb;
    moves->rb_rr = moves->ra_rr;
    temp_ra = moves->rra;
    temp_rb = moves->rrb;
    while (temp_ra && temp_rb)
    {
        temp_ra--;
        temp_rb--;
        moves->rrr++;
    }
    moves->rra_rrr = moves->rrr + temp_ra + temp_rb;
    moves->rrb_rrr = moves->rra_rrr;
    min = moves->ra_rrb;
    if (moves->rb_rra < min)
        min = moves->rb_rra;
    if(moves->ra_rr < min)
        min = moves->ra_rr;
    if(moves->rra_rrr < min)
        min = moves->rra_rrr;
    return (min);
}

int ft_count_move(t_list **a, t_list **b, t_list *elem, int max, int mid, t_moves *moves)
{
    int count;
    int max_a;

    ft_init_moves(moves);
    max = ft_lstsize(*b);
    max_a = ft_lstsize(*a);
    moves->rb = max - ft_lstsize(elem);
    moves->rrb = max - moves->rb;
    if (max == 1)
        moves->rrb = 0;
//    printf("MAX:%d, SIZE:%d, moves->rb:%d, moves->rrb:%d\n", max, ft_lstsize(elem), moves->rb, moves->rrb);
    count = ft_count_rotate_a(a, ((t_elem *)elem->content)->pos_order, mid);
    moves->ra = count;
    moves->rra = max_a - count;
    count = ft_define_min_moves(moves);
    return (count);
}

t_list *ft_select_el(t_list **a, t_list **b, int max, int mid, t_moves *moves)
{
    t_list *elem;
    int count_move;
    int min_count;
    t_list *min_elem;

    elem = *b;
    min_count = ft_count_move(a, b, elem, max, mid, moves);
    min_elem = elem;
    elem = elem->next;
    while (elem)
    {
        count_move = ft_count_move(a, b, elem, max, mid, moves);
        if (count_move < min_count)
        {
            min_count = count_move;
            min_elem = elem;
        }
        elem = elem->next;
    }
    return (min_elem);
}

int ft_push_a(t_list **a, t_list **b, t_list **res, int mid)
{
    t_list *elem;
    int max;
    t_moves *moves;
    int count;

    moves = malloc(sizeof(t_moves));
    if(!moves)
        return (0);
    if (!*b)
        return (1);
    max = ft_lstsize(*b);
    elem = ft_select_el(a, b, max, mid, moves);
//    ft_translate(a, b);
    count = ft_count_move(a, b, elem, max, mid, moves);
//    printf("CNT_RA:%d, CNT_RB:%d, CNT_RR:%d, CNT_RRR:%d\n", moves->ra, moves->rb, moves->rr, moves->rrr);
    if (moves->ra_rr == count)
    {
        while (moves->rr)
        {
            rr(a, b, res);
            moves->ra--;
            moves->rb--;
            moves->rr--;
        }
        while (moves->ra)
        {
            ra(a, res);
            moves->ra--;
        }
        while (moves->rb)
        {
            rb(b, res);
            moves->rb--;
        }
    }
    else if (moves->rra_rrr == count)
    {
        while (moves->rrr)
        {
            moves->rra--;
            moves->rrb--;
            moves->rrr--;
            rrr(a, b, res);
        }
        while (moves->rra)
        {
            rra(a, res);
            moves->rra--;
        }
        while (moves->rrb)
        {
            rrb(b, res);
            moves->rrb--;
        }
    }
    else if (moves->ra_rrb == count)
    {
        while (moves->ra)
        {
            ra(a, res);
            moves->ra--;
        }
        while (moves->rrb)
        {
            rrb(b, res);
            moves->rrb--;
        }
    }
    else if (moves->rb_rra == count)
    {
        while (moves->rra)
        {
            rra(a, res);
            moves->rra--;
        }
        while (moves->rb)
        {
            rb(b, res);
            moves->rb--;
        }
    }
    if(!pa(a, b, res))
        return (0);
//    ft_translate(a , b);
    ft_push_a(a, b, res, mid);
    return (1);
}

int ft_sorting(t_list **a, t_list **b, t_list **res)
{
    int max;
    int mid;

    max = ft_lstsize(*a);
    mid = max / 2;
    if(!ft_push_b(a, b, res, max, mid))
       return (0);
    ft_sort_3(a, res, 1);
//    ft_translate(a, b);
    ft_push_a(a, b, res, mid);
    return (1);
}

int ft_push_swap(t_list **a, t_list **b)
{
    t_list  *res;

    res = NULL;
    ft_define_order(*a);

    if (ft_check_sort(*a))
        return (1);
    else if (ft_lstsize(*a) == 3)
        ft_sort_3(a, &res, 1);
    else if (!ft_sorting(a, b, &res))
        return (0);
    while (A_POS_ORDER != 1)
        rra(a, &res);
    ft_print_cmnds(res);
    ft_lstclear(&res, free);
    return (1);
}
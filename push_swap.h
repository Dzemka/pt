#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>

typedef struct  s_stack
{
    int pos_order;
    int val;
    int flag;
}   t_elem;
typedef struct s_moves
{
    int ra;
    int rb;
    int rr;
    int ra_rr;
    int rb_rr;
    int sum_rotate;
    int rra;
    int rrb;
    int rrr;
    int rra_rrr;
    int rrb_rrr;
    int sum_reverse_rotate;
    int ra_rrb;
    int rb_rra;
    int sa;
    int sb;

} t_moves;
# define A_POS_ORDER ((t_elem *)(*a)->content)->pos_order
# define A_VAL ((t_elem *)(*a)->content)->val
# define A_FLAG ((t_elem *)(*a)->content)->flag
# define B_POS_ORDER ((t_elem *)(*b)->content)->pos_order
# define B_VAL ((t_elem *)(*b)->content)->val
# define B_FLAG ((t_elem *)(*b)->content)->flag


//utils functions
int ft_fill_stack(int argc, char **argv, t_list **a);
void    ft_print_cmnds(t_list *res);
int ft_count_same_flags(t_list *list);

//DELETE_AFTER
void    ft_translate(t_list **a, t_list **b);

//commands functions
int    sa(t_list **a, t_list **res);
int    sb(t_list **b, t_list **res);
int    ss(t_list **a, t_list **b, t_list **res);
int    ra(t_list **a, t_list **res);
int    rb(t_list **b, t_list **res);
int    rr(t_list **a, t_list **b, t_list **res);
int    pa(t_list **a, t_list **b, t_list **res);
int    pb(t_list **b, t_list **a, t_list **res);
int    rra(t_list **a, t_list **res);
int   rrb(t_list **b, t_list **res);
int    rrr(t_list **a, t_list **b, t_list **res);

//algorithm functions
void    ft_define_order(t_list *list);
int     ft_check_sort(t_list *list);

int select_rotate(int is_rotate, t_list **a, t_list **res);
int ft_push_swap(t_list **a, t_list **b);

#endif


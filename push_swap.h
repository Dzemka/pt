#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>

#define A_VAL *(int *)(*a)->content
#define ELEM_VAL *(int *)elem->content

typedef struct s_moves
{
    int ra;
    int rb;
    int rr;
    int ra_rb_rr;
    int rra;
    int rrb;
    int rrr;
    int rra_rrb_rrr;
    int ra_rrb;
    int rb_rra;
} t_moves;


//utils functions
int ft_fill_stack(int argc, char **argv, t_list **a);

//commands functions
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b);
void    pb(t_list **b, t_list **a);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

int     ft_check_sort(t_list *list);

int ft_push_swap(t_list **a, t_list **b);

#endif


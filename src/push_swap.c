#include "../push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if(ft_fill_stack(argc, argv, &a))
    {
        ft_push_swap(&a, &b);
    }
    else
        ft_putstr_fd("Error\n", 1);
    ft_lstclear(&a, free);
}
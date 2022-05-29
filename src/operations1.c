#include "push_swap.h"
#include <stdio.h>
void	push_b(t_info* info)
{
	ope_push(info->a, info->b);
	add_opelist(info, "pb");
	info->a->min = get_min_value(info->a);
	info->a->max = get_max_value(info->a);
	info->b->min = get_min_value(info->b);
	info->b->max = get_max_value(info->b);
}

void	push_a(t_info* info)
{
	ope_push(info->b, info->a);
	add_opelist(info, "pa");
	info->a->min = get_min_value(info->a);
	info->a->max = get_max_value(info->a);
	info->b->min = get_min_value(info->b);
	info->b->max = get_max_value(info->b);
}

void	swap_a(t_info* info)
{
	ope_swap(info->a);
	add_opelist(info, "sa");
}

void	swap_b(t_info* info)
{
	ope_swap(info->b);
	add_opelist(info, "sb");
}

void	swap_ab(t_info* info)
{
	ope_swap(info->a);
	ope_swap(info->b);
	add_opelist(info, "ss");
}

void	rotate_a(t_info* info)
{
	if (info->a->top == NULL || info->a->top->next == NULL)
		return ;
	ope_rotate(info->a);
	add_opelist(info, "ra");
}

void	rotate_b(t_info* info)
{
	if (info->b->top == NULL || info->b->top->next == NULL)
		return ;
	ope_rotate(info->b);
	add_opelist(info, "rb");
}

void	rotate_ab(t_info* info)
{
	if (info->b->top == NULL || info->b->top->next == NULL)
		return ;
	ope_rotate(info->a);
	ope_rotate(info->b);
	add_opelist(info, "rr");
}

void	reverse_a(t_info* info)
{
	ope_reverse(info->a);
	add_opelist(info, "rra");
}

void	reverse_b(t_info* info)
{
	ope_reverse(info->b);
	add_opelist(info, "rrb");
}

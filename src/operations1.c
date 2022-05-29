#include "push_swap.h"

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

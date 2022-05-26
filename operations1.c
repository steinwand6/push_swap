#include "push_swap.h"

void	push_b(t_info* info)
{
	ope_push(info->a, info->b);
	add_opelist(info, "pb");
}

void	push_a(t_info* info)
{
	ope_push(info->b, info->a);
	add_opelist(info, "pa");
}

void	rotate_a(t_info* info)
{
	ope_rotate(info->a);
	add_opelist(info, "ra");
}

void	rotate_b(t_info* info)
{
	ope_rotate(info->b);
	add_opelist(info, "rb");
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

#include "push_swap.h"

void	rotate_a(t_info *info)
{
	if (info->a->top == NULL || info->a->top->next == NULL)
		return ;
	ope_rotate(info->a);
	add_opelist(info, "ra");
}

void	rotate_b(t_info *info)
{
	if (info->b->top == NULL || info->b->top->next == NULL)
		return ;
	ope_rotate(info->b);
	add_opelist(info, "rb");
}

void	rotate_ab(t_info *info)
{
	if (info->a->top == NULL || info->a->top->next == NULL)
		return ;
	if (info->b->top == NULL || info->b->top->next == NULL)
		return ;
	ope_rotate(info->a);
	ope_rotate(info->b);
	add_opelist(info, "rr");
}

void	reverse_a(t_info *info)
{
	ope_reverse(info->a);
	add_opelist(info, "rra");
}

void	reverse_b(t_info *info)
{
	ope_reverse(info->b);
	add_opelist(info, "rrb");
}

#include "push_swap.h"

void	push_to_b_with_limit(t_info *info, int n)
{
	int	limit;

	limit = info->a->min + n;
	while (get_stack_size(info->a) > 0 && info->a->min < limit)
		push_worker(info, limit, n);
}

void	push_worker(t_info *info, int limit, int n)
{
	t_element	*elm;

	elm = info->a->top;
	if (elm->value <= limit)
		push_b(info);
	else if (elm->value != info->a->max && (elm->value > limit)
		 && (elm->value <= limit + (n / 3 * 2)))
	{
		push_b(info);
		smart_rotate(info, n);
	}
	else if (elm->next->value <= limit)
	{
		smart_swap(info, n);
		push_b(info);
	}
	else if (info->a->bottom->value <= limit)
	{
		reverse_a(info);
		push_b(info);
	}
	else
		rotate_a(info);
}

void	get_max_and_push_to_a(t_info *info)
{
	int	flg;

	flg = 0;
	while (info->b->top->value != info->b->max)
	{
		if (get_index_in_stack(info->b, info->b->max)
			> (get_stack_size(info->b) / 2))
			reverse_b(info);
		else
			rotate_b(info);
		if (info->b->top->value == info->b->max - 1)
		{
			push_a(info);
			flg = 1;
		}
	}
	push_a(info);
	if (flg)
	{
		if (info->b->top->value < info->b->top->next->value)
			swap_ab(info);
		else
			swap_a(info);
	}
}

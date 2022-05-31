#include "push_swap.h"

void smart_rotate(t_info *info, int n)
{
	int	limit;

	limit = info->a->min + n;
	if (info->a->top->value > limit &&
		!(info->a->top->value <= limit + (n /  3 * 2)))
		rotate_ab(info);
	else
		rotate_b(info);
}

void smart_swap(t_info *info, int n)
{
	int	limit;

	limit = info->a->min + n;
	if (info->b->top && info->b->top->next &&
		info->b->top->value < info->b->top->next->value &&
		info->b->top->next->value <= limit)
		swap_ab(info);
	else
		swap_a(info);
}

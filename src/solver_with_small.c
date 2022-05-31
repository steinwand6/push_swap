#include "push_swap.h"

void	_push_min(t_info *info)
{
	int	min_idx;

	min_idx = get_index_in_stack(info->a, get_min_value(info->a));
	if (min_idx == 1)
		rotate_a(info);
	else if (min_idx == 2)
	{
		rotate_a(info);
		rotate_a(info);
	}
	else if (min_idx == 3)
	{
		rotate_a(info);
		rotate_a(info);
		rotate_a(info);
	}
	else if (min_idx == 4)
		reverse_a(info);
	push_b(info);
}

void	solve_3_elements(t_info *info)
{
	t_element	*f;
	t_element	*s;
	t_element	*t;

	f = info->a->top;
	s = f->next;
	t = s->next;
	if (is_sorted_asc(info->a))
		return ;
	else if (f->value < s->value && s->value > t->value && f->value < t->value)
	{
		swap_a(info);
		rotate_a(info);
	}
	else if (f->value > s->value && s->value < t->value && f->value < t->value)
		swap_a(info);
	else if (f->value < s->value && s->value > t->value && f->value > t->value)
		reverse_a(info);
	else if (f->value > s->value && s->value < t->value && f->value > t->value)
		rotate_a(info);
	else
	{
		swap_a(info);
		reverse_a(info);
	}
}

void	solve_2_elements(t_info *info)
{
	t_element	*f;
	t_element	*s;

	f = info->a->top;
	s = f->next;
	if (f->value > s->value)
		swap_a(info);
}

void	solver_less_than_eq_5(t_info *info)
{
	if (get_stack_size(info->a) > 4)
		_push_min(info);
	if (get_stack_size(info->a) > 3)
		_push_min(info);
	if (get_stack_size(info->a) == 3)
		solve_3_elements(info);
	else if (get_stack_size(info->a) == 2)
		solve_2_elements(info);
	while (info->b->top)
		push_a(info);
}

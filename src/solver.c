#include "push_swap.h"

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
	if (f->value < s->value && s->value > t->value && f->value < t->value)
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


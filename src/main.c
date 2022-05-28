# include "push_swap.h"

# include <stdio.h>

int	get_median_value(t_stack *stack)
{
	int	size;
	int	min;

	size = get_stack_size(stack);
	min = get_min_value(stack);
	return (min + (size / 2));
}

int		get_index_in_stack(t_stack *stack, int to_find)
{
	int			index;
	t_element	*elm;

	index = 0;
	elm = stack->top;
	while (1)
	{
		if (to_find == elm->value)
			return (index);
		elm = elm->next;
		index++;
	}
}

void push_to_b_limit_100_order_by_asc(t_info *info)
{
	int	limit;
	int	min;
	t_element *elm;

	if (is_sorted_asc(info->a))
		return ;
	min = get_min_value(info->a);
	limit = min + 100;
	while (min < limit)
	{
		elm = info->a->top;
		if (elm->value <= limit)
			push_b(info);
		else if (elm->next->value <= limit)
		{
			if (info->b->top && info->b->top->next &&
				info->b->top->value < info->b->top->next->value)
				swap_ab(info);
			else
				swap_a(info);
			push_b(info);
		}
		else if (info->a->bottom->value <= limit)
		{
			reverse_a(info);
			push_b(info);
		}
		else
			rotate_a(info);
		min = get_min_value(info->a);
	}
}

void push_to_b_without_max(t_info *info)
{
	int	med;
	t_element *elm;

	if (is_sorted_asc(info->a))
		return ;
	med = get_median_value(info->a);
	while (get_min_value(info->a) < med)
	{
		elm = info->a->top;
		if (elm->value <= med)
			push_b(info);
		else if (elm->next && elm->next->value <= med)
		{
			if (info->b->top && info->b->top->next &&
				info->b->top->value < info->b->top->next->value)
				swap_ab(info);
			else
				swap_a(info);
			push_b(info);
		}
		else if (info->a->bottom && info->a->bottom->value <= med)
		{
			reverse_a(info);
			push_b(info);
		}
		else
			rotate_a(info);
	}
	if (get_stack_size(info->a) > 1)
		push_to_b_without_max(info);
}

void	get_max_and_push_to_a(t_info *info)
{
	t_element *elm;
	int		max;

	max = get_max_value(info->b);
	elm = info->b->top;
	if (get_index_in_stack(info->b, max) > (get_stack_size(info->b) / 2))
	{
		while (elm->value != max)
		{
			ope_reverse(info->b);
			add_opelist(info, "rrb");
			elm = info->b->top;
		}
	}
	else
	{
		while (elm->value != max)
		{
			rotate_b(info);
			elm = info->b->top;
		}
	}
	push_a(info);
}

void solver(t_info *info)
{
	t_stack *sa;
	t_stack *sb;
	t_element *elm;

	sa = info->a;
	sb = info->b;
	while (get_stack_size(info->a) > 100 && !is_sorted_asc(info->a))
		push_to_b_limit_100_order_by_asc(info);
	push_to_b_without_max(info);
	while (sb->top)
	{
		get_max_and_push_to_a(info);
	}
	while (sa->top)
	{
		elm = pop(sa);
		free(elm);
	}
	free(sb);
}

void free_oplist(t_opelist *elm)
{
	t_opelist *tmp;

	while (elm)
	{
		free(elm->op);
		tmp = elm->next;
		free(elm);
		elm = tmp;
	}
}

int main(int argc, char *argv[])
{
	t_info info;
	int *values;

	if (argc == 1 || argc == 2)
		return (0);
	init_info(&info, argc);
	values = convert_array(&(argv[1]), argc - 1);
	values = coordinate_compression(values, argc - 1);
	create_stack_from_array(&info, values);
	reverse_stack(&info);
	solver(&info);
	free(values);
	t_opelist *list = info.opelist;
	while (info.opelist)
	{
		printf("%s\n", info.opelist->op);
		info.opelist = info.opelist->next;
	}
	free_oplist(list);
	free(info.a);
}

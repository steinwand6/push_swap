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

void push_core(t_info *info, int limit, int n)
{
	t_element *elm;

	elm = info->a->top;
	if (elm->value <= limit)
		push_b(info);
	else if (elm->value != info->a->max && (elm->value > limit)
			 && (elm->value <= limit + (n /  3 * 2)))
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

void push_to_b_with_limit(t_info *info, int n)
{
	int	limit;
	
	limit = info->a->min + n;
	while (info->a->min < limit)
		push_core(info, limit, n);
}

void	get_max_and_push_to_a(t_info *info)
{
	t_element *elm;
	int flg = 0;

	elm = info->b->top;
	while (elm->value != info->b->max)
	{
		if (get_index_in_stack(info->b, info->b->max)
			>(get_stack_size(info->b) / 2))
			reverse_b(info);
		else
			rotate_b(info);
		elm = info->b->top;
		if (flg == 0 && elm->value == info->b->max - 1)
		{
			push_a(info);
			flg = 1;
		}
	}
	push_a(info);
	if (flg)
	{
		flg = 0;
		if (info->b->top->value < info->b->top->next->value)
			swap_ab(info);
		else
			swap_a(info);
	}
}

void solver(t_info *info)
{
	t_stack *sb;

	sb = info->b;
	if (get_stack_size(info->a) <= 5)
		solver_less_than_eq_5(info);
	else
	{
		while (get_stack_size(info->a) >= 300  && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 9);
		while (get_stack_size(info->a) >= 200  && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 7);
		while (get_stack_size(info->a) >= 100 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a)/ 5);
		while (get_stack_size(info->a) > 10 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a)/ 4);
		while (get_stack_size(info->a) > 1)
			push_to_b_with_limit(info, 15);
		push_to_b_with_limit(info, info->a->max-1);
		while (sb->top)
			get_max_and_push_to_a(info);
	}
}

void print_operations(t_info *info)
{
	t_opelist *list;

	list = info->opelist;
	while (list)
	{
		ft_putendl_fd(list->op, 1);
		list = list->next;
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
		if (is_sorted_asc(info.a))
	{
		free_opelist(info.opelist);
		free_stack(info.b);
		free_stack(info.a);
		return 0;
	}
	solver(&info);
	free(values);
	print_operations(&info);
	free_opelist(info.opelist);
	free_stack(info.b);
	free_stack(info.a);
}

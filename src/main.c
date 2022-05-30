#include "push_swap.h"

void push_to_b_with_limit(t_info *info, int n)
{
	int	limit;
	t_element *elm;

	limit = info->a->min + n;
	while (info->a->min < limit)
	{
		elm = info->a->top;
		if (elm->value <= limit)
			push_b(info);
		else if (elm->value != info->a->max &&
				 (elm->value > limit)
				 && (elm->value <= limit + (n /  3 * 2)))
		{
			push_b(info);
			if (info->a->top->value > limit &&
				!(info->a->top->value <= limit + (n /  3 * 2)))
				rotate_ab(info);
			else
				rotate_b(info);
			elm = info->a->top;
		}
		else if (elm->next->value <= limit)
		{
			if (info->b->top && info->b->top->next &&
				info->b->top->value < info->b->top->next->value &&
				info->b->top->next->value <= limit)
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
	}
}

void	get_max_and_push_to_a(t_info *info)
{
	t_element *elm;

	elm = info->b->top;
	if (get_index_in_stack(info->b, info->b->max) > (get_stack_size(info->b) / 2))
	{
		while (elm->value != info->b->max)
		{
			ope_reverse(info->b);
			add_opelist(info, "rrb");
			elm = info->b->top;
		}
	}
	else
	{
		while (elm->value != info->b->max)
		{
			rotate_b(info);
			elm = info->b->top;
		}
	}
	push_a(info);
}

void solver(t_info *info)
{
	t_stack *sb;

	sb = info->b;
	if (get_stack_size(info->a) == 3)
		solve_3_elements(info);
	else if (get_stack_size(info->a) == 2)
		solve_2_elements(info);
	else if (get_stack_size(info->a) == 4)
		solve_4_elements(info);
	else if (get_stack_size(info->a) == 5)
		solve_5_elements(info);
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

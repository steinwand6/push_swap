#include "push_swap.h"

void	solver(t_info *info)
{
	t_stack	*sb;

	sb = info->b;
	if (get_stack_size(info->a) <= 5)
		solver_less_than_eq_5(info);
	else
	{
		while (get_stack_size(info->a) >= 300 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 9);
		while (get_stack_size(info->a) >= 200 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 7);
		while (get_stack_size(info->a) >= 100 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 5);
		while (get_stack_size(info->a) > 10 && !is_sorted_asc(info->a))
			push_to_b_with_limit(info, get_stack_size(info->a) / 4);
		while (get_stack_size(info->a) > 1)
			push_to_b_with_limit(info, info->a->max - 1);
		while (sb->top)
			get_max_and_push_to_a(info);
	}
}

void	print_operations(t_info *info)
{
	t_opelist	*list;

	list = info->opelist;
	while (list)
	{
		ft_putendl_fd(list->op, 1);
		list = list->next;
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		*values;

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
		return (0);
	}
	solver(&info);
	free(values);
	print_operations(&info);
	deinit_info(&info);
}

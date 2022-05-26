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

void push_to_b_without_max(t_info *info)
{
	int	med;
	t_element *elm;

	med = get_median_value(info->a);
	while (get_min_value(info->a) < med)
	{
		elm = info->a->top;
		if (elm->value <= med)
		{
			ope_push(info->a, info->b);
			add_opelist(info, "pb");
		}
		ope_rotate(info->a);
		add_opelist(info, "ra");
	}
	if (get_stack_size(info->a) > 1)
		push_to_b_without_max(info);
}

int		get_max_index(t_stack *stack, int max)
{
	int			index;
	t_element	*elm;

	index = 0;
	elm = stack->top;
	while (1)
	{
		if (max == elm->value)
			return (index);
		elm = elm->next;
		index++;
	}
	return (-1);
}

void	get_max_and_push_to_a(t_info *info)
{
	t_element *elm;
	int		max;

	max = get_max_value(info->b);
	elm = info->b->top;
	if (get_max_index(info->b, max) > (get_stack_size(info->b) / 2))
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
			ope_rotate(info->b);
			add_opelist(info, "rb");
			elm = info->b->top;
		}
	}
	ope_push(info->b, info->a);
	add_opelist(info, "pa");
}

void solver(t_info *info)
{
	t_stack *sa;
	t_stack *sb;
	t_element *elm;

	sa = info->a;
	sb = info->b;
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

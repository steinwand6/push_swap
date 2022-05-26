# include "push_swap.h"

# include <stdio.h>

void print_stack(t_stack *stack)
{
	t_element *el = stack->top;
	while (el)
	{
		printf("%d ->", el->value);
		el = el->next;
	}
	puts("");

}

int	get_medium_value(t_stack *stack)
{
	int	size;
	int	min;

	size = get_stack_size(stack);
	min = get_min_value(stack);
	return (min + (size / 2));
}

void solver(t_info *info)
{
	t_stack *sa;
	t_stack *sb;
	t_element *elm;

	sa = info->a;
	sb = info->b;
	while (get_stack_size(sa) > 1)
	{
		if (sa->top->value == get_min_value(sa))
		{
			ope_push(sa, sb);
			add_opelist(info, "pb");
		}
		else
		{
			ope_rotate(sa);
			add_opelist(info, "ra");
		}
	}
	while (sb->top)
	{
		ope_push(sb, sa);
		add_opelist(info, "pa");
	}
	while (sa->top)
	{
		elm = pop(sa);
		//printf("%d -> ", elm->value);
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
		free(info.opelist->op);
		info.opelist = info.opelist->next;
	}
	free_oplist(list);
	free(info.a);
}

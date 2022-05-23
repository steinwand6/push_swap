# include "push_swap.h"

# include <stdio.h>

void solver(t_stack *sa)
{
	t_stack *sb;
	t_element *elm;

	sb = new_stack();
	while (get_stack_size(sa) > 1)
	{
		if (sa->top->value == get_min_value(sa))
		{
			ope_push(sa, sb);
			printf("pb\n");
		}
		else
		{
			ope_rotate(sa);
			printf("ra\n");
		}
	}
	while (sb->top)
	{
		ope_push(sb, sa);
		printf("pa\n");
	}
	while (sa->top)
	{
		elm = pop(sa);
		//printf("%d -> ", elm->value);
		free(elm);
	}
	free(sb);
}

int main(int argc, char *argv[])
{
	t_stack *sa;
	int *values;

	sa = new_stack();
	if (sa == NULL)
		return 1;
	if (argc == 1)
		return 1;
	values = convert_array(&(argv[1]), argc - 1);
	values = coordinate_compression(values, argc - 1);
	free(values);
	create_stack_from_array(sa, values, argc - 1);
	reverse_stack(sa);
	solver(sa);
	free(sa);
}

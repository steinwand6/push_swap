# include "push_swap.h"

# include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *sa;
	int *values;
	//t_stack *sb;

	sa = new_stack();
	if (sa == NULL)
		return 1;
	if (argc == 1)
		return 1;
	values = convert_array(&(argv[1]), argc - 1);
	create_stack_from_array(sa, values, argc - 1);
	t_element *elm;
	reverse_stack(sa);
	while (sa->top)
	{
		elm = pop(sa);
		printf("%d\n", elm->value);
		free(elm);
	}
	free(sa);
}

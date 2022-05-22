# include "push_swap.h"

# include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned int u;
	t_stack *sa;
	//t_stack *sb;

	sa = new_stack();
	if (sa == NULL)
		return 1;
	if (argc == 1)
		return 1;
	u = 1;
	while (argv[u])
	{
		if (push_with_validate(sa, argv[u]))
			return 1;
		u++;
	}
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

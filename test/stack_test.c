#include <stdio.h>

#include "../include/push_swap.h"

#include "../src/utils.c"
#include "../src/ft_atol.c"
#include "../src/stack.c"
#include "../src/element.c"

int main()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	t_element *prev;
	t_element *new_one;

	stack->top = NULL;
	stack->bottom = NULL;
	for (int i = 0; i < 10; i++) {
		new_one = new_element(i);
		new_one->value = array[i];
		push(stack, new_one);
	}
	while (stack->top)
	{
		t_element *val = pop(stack);
		printf("%d\n", val->value);
		free(val);
	}
	free(stack);
}

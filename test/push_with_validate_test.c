#include <stdio.h>
#include <limits.h>

#include "../include/push_swap.h"
#include "../src/element.c"
#include "../src/utils.c"
#include "../src/ft_atol.c"
#include "../src/stack.c"

int main(int argc, char *argv[])
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	stack->top = NULL;
	stack->bottom = NULL;

	for (int i = 0; i < 10; i++) {
		if (push_with_validate(stack, array[i]))
			printf("validated with %s\n", array[i]);
	}
	while (stack->top)
	{
		t_element *val = pop(stack);
		printf("%d\n", val->value);
		free(val);
	}

	char *array2[10] = {"2147483647", "-2147483648", "+2147483647", "a", "4", "-500", "+-6", "7", "8", "2200000000"};
	for (int i = 0; i < 10; i++) {
		if (push_with_validate(stack, array2[i]))
			printf("validated with %s\n", array2[i]);
	}
	while (stack->top)
	{
		t_element *val = pop(stack);
		printf("%d\n", val->value);
		free(val);
	}
	free(stack);
}

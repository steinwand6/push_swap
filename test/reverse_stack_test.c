#include <stdio.h>
#include <limits.h>

#include "../include/push_swap.h"
#include "../src/element.c"
#include "../src/utils.c"
#include "../src/ft_atol.c"
#include "../src/stack.c"

int case1()
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
	reverse_stack(stack);
	while (stack->top)
	{
		t_element *val = pop(stack);
		printf("%d(nowtop: %p) -> ", val->value, stack->top);
		free(val);
	}
	puts("");
	free(stack);
}

int case2()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"10"};

	stack->top = NULL;
	stack->bottom = NULL;

	for (int i = 0; i < 1; i++) {
		if (push_with_validate(stack, array[i]))
			printf("validated with %s\n", array[i]);
	}
	reverse_stack(stack);
	while (stack->top)
	{
		t_element *val = pop(stack);
		printf("%d -> ", val->value);
		free(val);
	}
	puts("");
	free(stack);
}


int main(int argc, char *argv[])
{
	case1();
	puts("------------");
	case2();
}

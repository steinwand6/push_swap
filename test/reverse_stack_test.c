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

	int *vals = convert_array(array, 10);
	create_stack_from_array(stack, vals, 10);
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

	int *vals = convert_array(array, 1);
	create_stack_from_array(stack, vals, 1);
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

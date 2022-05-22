#include <stdio.h>
#include <limits.h>

#include "../include/push_swap.h"
#include "../src/element.c"
#include "../src/utils.c"
#include "../src/ft_atol.c"
#include "../src/stack.c"
#include "../src/coordinate_compression.c"

int case1()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "-100", "3", "4", "5", "-200000", "7", "8", "9"};

	stack->top = NULL;
	stack->bottom = NULL;

	int *vals = convert_array(array, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d -> ", vals[i]);
	}
	puts("");
	int *sorted = coordinate_compression(vals, 10);
	create_stack_from_array(stack, sorted, 10);
	free(vals);
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

int case2()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "-100", "3", "8", "5", "-200000", "7", "8", "9"};

	stack->top = NULL;
	stack->bottom = NULL;

	int *vals = convert_array(array, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d -> ", vals[i]);
	}
	puts("");
	int *comped = coordinate_compression(vals, 10);
	create_stack_from_array(stack, comped, 10);
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
	puts("------------");
	puts("normal");
	case1();
	puts("------------");
	/* puts("duplicate"); */
	/* case2(); */
	/* puts("------------"); */
	/* puts("------------"); */
	/* case2(); */
}

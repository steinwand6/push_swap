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

	int *values = array_convert(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d -> ", values[i]);
	}
	puts("");
	free(stack);
}

int case2()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "-2147483649"};

	int *values = array_convert(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d -> ", values[i]);
	}
	puts("");
	free(stack);
}

int case3()
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "2147483648"};

	int *values = array_convert(array, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d -> ", values[i]);
	}
	puts("");
	free(stack);
}

int main(int argc, char *argv[])
{
	case1();
	puts("------------");
	case2();
	puts("------------");
	case3();
}

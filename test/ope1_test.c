#include <stdio.h>
#include <limits.h>

#include "../include/push_swap.h"
#include "../src/element.c"
#include "../src/utils.c"
#include "../src/ft_atol.c"
#include "../src/stack.c"
#include "../src/ope1.c"

int main(int argc, char *argv[])
{
	t_stack *sa;
	t_stack *sb;
	sa = malloc(sizeof(t_stack));
	sb = malloc(sizeof(t_stack));
	char *array[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	sa->top = NULL;
	sa->bottom = NULL;

	for (int i = 0; i < 10; i++) {
		push_with_validate(sa, array[i]);
	}
	ope_swap(sa);
	while (sa->top)
		ope_push(sa, sb);
	for (int i = 0; i < 5; i++)
		ope_push(sb, sa);
	t_element *elm;
	while (sa->top)
	{
		elm = pop(sa);
		printf("%d\n", elm->value);
		free(elm);
	}
	while (sb->top)
	{
		elm = pop(sb);
		printf("%d\n", elm->value);
		free(elm);
	}
	free(sa);
	free(sb);
}

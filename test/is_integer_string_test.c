#include <stdio.h>
#include <limits.h>

#include "../include/push_swap.h"
#include "../src/utils.c"

int test(int isError, int val, int expect)
{
	if (isError)
		return 0;
	if (val != expect)
		printf("val(%d) : expect(%d)\n", val, expect);
	return (val == expect);
}

int main(int argc, char *argv[])
{
	test(0, is_integer_string("1000"), 1);
	test(0, is_integer_string("-1000"), 1);
	test(0, is_integer_string("0"), 1);
	test(0, is_integer_string("-1"), 1);
	test(0, is_integer_string("20000000000000000"), 1);

	test(0, is_integer_string("-"), 0);
	test(0, is_integer_string("a"), 0);
	test(0, is_integer_string("12-"), 0);
	test(0, is_integer_string("\1"), 0);
	test(0, is_integer_string(""), 0);

	if (argc == 1)
		return 0;

	int i = 1;
	while (argv[i])
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		test(0, is_integer_string(argv[i]), 1);
		i++;
	}
}

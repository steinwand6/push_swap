#include <stdio.h>
#include <limits.h>
#include "../include/push_swap.h"

#include "../src/ft_atol.c"

int test(int isError, long val, long expect)
{
	if (isError)
		return 0;
	if (val != expect)
		printf("val(%d) : expect(%d)\n", val, expect);
	return (val == expect);
}

int main()
{
	test(0, ft_atol("1000"), 1000);
	test(0, ft_atol("2147483647"), INT_MAX);
	test(0, ft_atol("-2147483648"), INT_MIN);
	test(0, ft_atol("0"), 0);
	test(0, ft_atol("2147483648"), 2147483648);
	test(0, ft_atol("-2147483649"), -2147483649);
}

#include "push_swap.h"

int	is_integer_string(char *str)
{
	int	i;
	int	is_int_str;

	is_int_str = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		else if (ft_isdigit(str[i]))
		{
			is_int_str = 1;
			i++;
		}
		else
			return (0);
	}
	return (is_int_str);
}

int	get_median_value(t_stack *stack)
{
	int	size;
	int	min;

	size = get_stack_size(stack);
	min = get_min_value(stack);
	return (min + (size / 2));
}

int		get_index_in_stack(t_stack *stack, int to_find)
{
	int			index;
	t_element	*elm;

	index = 0;
	elm = stack->top;
	while (1)
	{
		if (to_find == elm->value)
			return (index);
		elm = elm->next;
		index++;
	}
}

int	is_recommended_rr(t_stack *stack, int limit)
{
	t_element	*elm;
	int	count_a;
	int	count_b;

	elm = stack->top;
	count_a = 0;
	while (elm->value <= limit)
	{
		elm = elm->next;
		count_a++;
	}
	elm = stack->bottom;
	count_b = 1;
	while (elm->value <= limit)
	{
		elm = elm->prev;
		count_b++;
	}
	return (count_a > count_b);
}

int	get_second_value(t_stack *stack)
{
	int second;
	t_element *elm;

	second = 0;
	elm = stack->top;
	while (elm)
	{
		if (second < elm->value && elm->value != stack->max)
			second = elm->value;
		elm = elm->next;
	}
	return (second);
}

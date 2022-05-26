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

int	is_sorted_asc(t_stack *stack)
{
	t_element	*elm;
	int			prev;

	prev = INT_MIN;
	elm = stack->top;
	while (elm)
	{
		if (elm->value < prev)
			return (0);
		prev = elm->value;
		elm = elm->next;
	}
	return (1);
}

void	reverse_stack(t_info *info)
{
	t_element	*elm;
	t_element	*store;
	t_stack		*sa;

	sa = info->a;
	elm = sa->bottom;
	sa->top = sa->bottom;
	while (elm)
	{
		store = elm->prev;
		elm->prev = elm->next;
		elm->next = store;
		sa->bottom = elm;
		elm = store;
	}
}

int		get_stack_size(t_stack *stack)
{
	int			size;
	t_element	*elm;

	size = 0;
	elm = stack->top;
	while (elm)
	{
		elm = elm->next;
		size++;
	}
	return (size);
}

int		get_max_value(t_stack *stack)
{
	int			max;
	t_element	*elm;

	max = 0;
	elm = stack->top;
	while (elm)
	{
		if (max < elm->value)
			max = elm->value;
		elm = elm->next;
	}
	return (max);
}

int		get_min_value(t_stack *stack)
{
	int			min;
	t_element	*elm;

	min = INT_MAX;
	elm = stack->top;
	while (elm)
	{
		if (min > elm->value)
			min = elm->value;
		elm = elm->next;
	}
	return (min);
}

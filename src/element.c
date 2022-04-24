#include "push_swap.h"

t_element *new_element(int value)
{
	t_element *ptr;

	ptr = malloc(sizeof(t_element));
	if (ptr == NULL)
		return (NULL);
	ptr->value = value;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

int push_with_validate(t_stack *stack, char *val)
{
	long	num;
	t_element *new_el;

	if (!is_integer_string(val))
		return (-1);
	num = ft_atol(val);
	if (num < INT_MIN || INT_MAX < num)
		return (-1);
	new_el = new_element((int)num);
	if (!new_el)
		return (-1);
	push(stack, new_el);
	return (0);
}

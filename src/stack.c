#include "push_swap.h"

void push(t_stack *self, t_element *elm)
{
	if (self->top)
	{
		elm->next = self->top;
		self->top->prev = elm;
	}
	else
	{
		self->bottom = elm;
		elm->next = NULL;
	}
	self->top = elm;
}

t_element *pop(t_stack *self)
{
	t_element *elm;

	elm = NULL;
	if (self->top == NULL)
		return elm;
	elm = self->top;
	self->top = elm->next;
	if (self->top)
		self->top->prev = NULL;
	elm->prev = NULL;
	elm->next = NULL;
	return elm;
}

t_stack *new_stack(void)
{
	t_stack *ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->top = NULL;
	ptr->bottom = NULL;
	return (ptr);
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

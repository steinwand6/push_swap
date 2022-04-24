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
	return elm;
}

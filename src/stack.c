#include "push_swap.h"

void push(t_stack *self, t_element *elm)
{
	if (self->bottom)
	{
		self->bottom->next = elm;
		elm->prev = self->bottom;
	}
	else
	{
		self->top = elm;
	}
	self->bottom = elm;
}

t_element *pop(t_stack *self)
{
	t_element *elm;

	elm = NULL;
	if (self->bottom == NULL)
		return elm;
	self->bottom->next = NULL;
	elm = self->bottom;
	self->bottom = elm->prev;
	return elm;
}

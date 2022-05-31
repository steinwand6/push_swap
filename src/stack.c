#include "push_swap.h"

void	push(t_stack *self, t_element *elm)
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

t_element	*pop(t_stack *self)
{
	t_element	*elm;

	elm = NULL;
	if (self->top == NULL)
		return (elm);
	elm = self->top;
	self->top = elm->next;
	if (self->top)
		self->top->prev = NULL;
	elm->prev = NULL;
	elm->next = NULL;
	return (elm);
}

t_stack	*new_stack(void)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->top = NULL;
	ptr->bottom = NULL;
	return (ptr);
}

int	create_stack_from_array(t_info *info, int *val)
{
	int			i;
	t_element	*new_el;

	i = 0;
	while (i < info->count)
	{
		if (val[i] < INT_MIN || INT_MAX < val[i])
			return (-1);
		new_el = new_element(val[i]);
		if (!new_el)
			return (-1);
		push(info->a, new_el);
		i++;
	}
	info->a->max = info->count - 1;
	info->b->max = info->count - 1;
	info->a->min = 0;
	return (0);
}

int	get_index_in_stack(t_stack *stack, int to_find)
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

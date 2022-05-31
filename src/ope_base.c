#include "push_swap.h"

void	ope_swap(t_stack *stack)
{
	t_element	*top;
	t_element	*second;
	int			tmp;

	top = stack->top;
	if (!top || !(top->next))
		return ;
	second = top->next;
	tmp = second->value;
	second->value = top->value;
	top->value = tmp;
}

void	ope_push(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*a_top;

	a_top = pop(stack_a);
	if (a_top != NULL)
		push(stack_b, a_top);
}

void	ope_rotate(t_stack *stack)
{
	t_element	*top;
	t_element	*btm;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	top = pop(stack);
	btm = stack->bottom;
	btm->next = top;
	stack->bottom = top;
	top->prev = btm;
	top->next = NULL;
}

void	ope_reverse(t_stack *stack)
{
	t_element	*top;
	t_element	*btm;

	if (stack->top->next == NULL)
		return ;
	top = stack->top;
	btm = stack->bottom;
	stack->bottom = btm->prev;
	stack->bottom->next = NULL;
	btm->next = top;
	top->prev = btm;
	btm->prev = NULL;
	stack->top = btm;
}

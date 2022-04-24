# include "push_swap.h"

void ope_swap(t_stack *stack)
{
	t_element *top;
	t_element *second;
	t_element *third;

	top = stack->top;
	if (!top || !(top->next))
		return ;
	second = top->next;
	third = second->next;
	
	stack->top = second;
	top->next = third;
	top->prev = second;
	third->prev = top;
	second->prev = NULL;
	second->next = top;
}

void ope_push(t_stack *stack_a, t_stack *stack_b)
{
	t_element *a_top;

	a_top = pop(stack_a);
	if (a_top != NULL)
		push(stack_b, a_top);
}

void ope_rotate(t_stack *stack)
{
	t_element *top;
	t_element *btm;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	top = pop(stack);
	btm = stack->bottom;
	btm->next = top;
	stack->bottom = top;
	top->prev = btm;
	top->next = NULL;
}

void ope_reverse(t_stack *stack)
{
	t_element *top;
	t_element *btm;

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

# include "push_swap.h"

void ope_swap(t_stack *stack)
{
	t_element *top;
	t_element *second;
	t_element *third;

	if (!top || !(top->next))
		return ;
	top = stack->top;
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
	push(stack_b, a_top);
}

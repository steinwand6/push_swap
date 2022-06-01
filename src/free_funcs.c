#include "push_swap.h"

void	free_opelist(t_opelist *elm)
{
	t_opelist	*tmp;

	while (elm)
	{
		free(elm->op);
		tmp = elm->next;
		free(elm);
		elm = tmp;
	}
}

void	free_stack(t_stack *stack)
{
	t_element	*elm;

	elm = pop(stack);
	while (elm)
	{
		free(elm);
		elm = pop(stack);
	}
	free(stack);
}

void	free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

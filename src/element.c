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

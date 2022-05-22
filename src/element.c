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

int		*array_convert(char **argv, size_t size)
{
	int *array;
	size_t	i;
	long	val;

	array = malloc(sizeof(int) * (size + 1));
	if (array == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		val = atol(argv[i]);
		if (val < INT_MIN || val > INT_MAX)
			exit(1);
		array[i] = val;
		i++;
	}
	return array;
}

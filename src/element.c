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

int		*array_convert(char **argv, int size)
{
	int *array;
	int	i;
	long	val;

	array = malloc(sizeof(int) * (size + 1));
	if (array == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		if (!is_integer_string(argv[i]))
			exit (1);
		val = atol(argv[i]);
		if (val < INT_MIN || val > INT_MAX)
			exit(1);
		array[i] = val;
		i++;
	}
	return array;
}

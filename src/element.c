#include "push_swap.h"

t_element	*new_element(int value)
{
	t_element	*ptr;

	ptr = malloc(sizeof(t_element));
	if (ptr == NULL)
		return (NULL);
	ptr->value = value;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

int	*convert_array(char **argv, int size)
{
	int		*array;
	int		i;
	long	val;

	array = malloc(sizeof(int) * (size));
	if (array == NULL)
		exit(1);
	i = 0;
	while (i < size)
	{
		if (!is_integer_string(argv[i]))
		{
			free(array);
			return (NULL);
		}
		val = atol(argv[i]);
		if (val < INT_MIN || val > INT_MAX)
		{
			free(array);
			return (NULL);
		}
		array[i] = val;
		i++;
	}
	return (array);
}

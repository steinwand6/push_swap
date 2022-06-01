#include "push_swap.h"

static int	*copy_array(int *array, size_t size)
{
	int		*vals;
	size_t	i;

	vals = malloc(sizeof(int) * size);
	if (vals == NULL)
		exit_error();
	i = 0;
	while (i < size)
	{
		vals[i] = array[i];
		i++;
	}
	return (vals);
}

static void	quick_sort(int *array, int left, int right)
{
	int	shaft;
	int	temp;
	int	i;
	int	j;

	if (left < right)
	{
		shaft = array[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while (1)
		{
			while (array[++i] < shaft)
				;
			while (array[--j] > shaft)
				;
			if (i >= j)
				break ;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		quick_sort(array, left, i - 1);
		quick_sort(array, j + 1, right);
	}
}

int	check_duplicate(int *array, int size)
{
	int	prev;
	int	i;

	prev = array[0];
	i = 1;
	while (i < size)
	{
		if (prev == array[i])
			return (1);
		prev = array[i];
		i++;
	}
	return (0);
}

int	get_index(int to_find, int *array, int left, int right)
{
	int	middle;

	while (left <= right)
	{
		middle = (left + right) / 2;
		if (to_find == array[middle])
			break ;
		else if (to_find < array[middle])
			right = middle;
		else
			left = middle;
	}
	return ((left + right) / 2);
}

int	*coordinate_compression(int *sa, int size)
{
	int	*vals;
	int	i;

	vals = copy_array(sa, size);
	quick_sort(vals, 0, size - 1);
	if (check_duplicate(vals, size))
	{
		free(sa);
		free(vals);
		exit_error();
	}
	i = 0;
	while (i < size)
	{
		sa[i] = get_index(sa[i], vals, 0, size);
		i++;
	}
	free(vals);
	return (sa);
}

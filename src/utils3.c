#include "push_swap.h"

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	count_elements_in_array(char **array)
{
	int		count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

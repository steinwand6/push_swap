# include "push_swap.h"

int is_integer_string(char *str)
{
	int i;
	int is_int_str;

	is_int_str = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		else if (ft_isdigit(str[i]))
		{
			is_int_str = 1;
			i++;
		}
		else
			return (0);
	}
	return (is_int_str);
}

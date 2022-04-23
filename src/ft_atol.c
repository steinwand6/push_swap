#include "push_swap.h"

static	char	*ft_del_space(const char *str)
{
	while (*str && (*str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v' || *str == ' '))
		str++;
	return ((char *)str);
}

static	long	ft_get_long_max_or_min(int sign)
{
	if (sign)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

long	ft_atol(const char *str)
{
	int				sign;
	unsigned long	result;

	str = ft_del_space(str);
	sign = *str == '-';
	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((result << 1) > LONG_MAX || (result << 2) > LONG_MAX
			|| (result << 3) > LONG_MAX
			|| (result * 10 + (*str - '0')) > LONG_MAX)
			return (ft_get_long_max_or_min(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * ((sign * -2) + 1));
}

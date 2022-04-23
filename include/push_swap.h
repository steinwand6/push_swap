#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_element
{
	int		value;
    struct s_element		*next;
    struct s_element		*prev;
}				t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
}				t_stack;

void push(t_stack *self, t_element *elm);
t_element *pop(t_stack *self);

#endif

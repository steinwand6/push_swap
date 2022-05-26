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

typedef struct s_opelist
{
	char		*ope;
    struct s_opelist		*next;
    struct s_opelist		*prev;
}				t_opelist;

typedef struct s_info
{
	t_stack		*a;
	t_stack		*b;
	t_opelist	*opelist;
	int			count;
}				t_info;

void push(t_stack *self, t_element *elm);
t_element *pop(t_stack *self);
int is_integer_string(char *str);
int create_stack_from_array(t_stack *, int *, int);
long	ft_atol(const char *str);
void ope_swap(t_stack *sa);
void ope_push(t_stack *sa, t_stack *sb);
void ope_rotate(t_stack *stack);
void ope_reverse(t_stack *stack);
t_element *new_element(int value);
t_stack *new_stack(void);
int		*convert_array(char **, int);
void reverse_stack(t_stack *sa);
int	*coordinate_compression(int *sa, int size);
int		get_stack_size(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);

#endif

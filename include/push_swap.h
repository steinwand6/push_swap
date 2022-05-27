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
	char		*op;
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
int create_stack_from_array(t_info *, int *);
long	ft_atol(const char *str);
void ope_swap(t_stack *sa);
void ope_push(t_stack *sa, t_stack *sb);
void ope_rotate(t_stack *stack);
void ope_reverse(t_stack *stack);
t_element *new_element(int value);
t_stack *new_stack(void);
int		*convert_array(char **, int);
void reverse_stack(t_info *);
int	*coordinate_compression(int *sa, int size);
int		get_stack_size(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);
void	init_info(t_info *info, int count);
void	add_opelist(t_info *, const char *);
void	push_b(t_info*);
void	push_a(t_info*);
void	swap_b(t_info*);
void	swap_a(t_info*);
void	rotate_b(t_info*);
void	rotate_a(t_info*);
void	reverse_a(t_info* info);
int	is_sorted_asc(t_stack *stack);
void	swap_ab(t_info* info);

#endif

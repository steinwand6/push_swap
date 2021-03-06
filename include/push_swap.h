#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_element
{
	int					value;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_stack
{
	t_element	*top;
	t_element	*bottom;
	int			min;
	int			max;
}				t_stack;

typedef struct s_opelist
{
	char				*op;
	struct s_opelist	*next;
	struct s_opelist	*prev;
}				t_opelist;

typedef struct s_info
{
	t_stack		*a;
	t_stack		*b;
	t_opelist	*opelist;
	int			count;
}				t_info;

void		push(t_stack *self, t_element *elm);
t_element	*pop(t_stack *self);
int			is_integer_string(char *str);
int			create_stack_from_array(t_info *stack, int *array);
long		ft_atol(const char *str);
void		ope_swap(t_stack *sa);
void		ope_push(t_stack *sa, t_stack *sb);
void		ope_rotate(t_stack *stack);
void		ope_reverse(t_stack *stack);
t_element	*new_element(int value);
t_stack		*new_stack(void);
int			*convert_array(char **array, int count);
void		reverse_stack(t_info *info);
int			*coordinate_compression(int *sa, int size);
int			get_stack_size(t_stack *stack);
int			get_max_value(t_stack *stack);
int			get_min_value(t_stack *stack);
void		init_info(t_info *info, int count);
void		add_opelist(t_info *info, const char *ope);
void		push_b(t_info *info);
void		push_a(t_info *info);
void		swap_b(t_info *info);
void		swap_a(t_info *info);
void		rotate_b(t_info *info);
void		rotate_a(t_info *info);
void		rotate_ab(t_info *info);
void		reverse_a(t_info *info);
void		reverse_b(t_info *info);
int			is_sorted_asc(t_stack *stack);
void		swap_ab(t_info *info);
int			get_second_value(t_stack *stack);
int			is_recommended_rr(t_stack *stack, int limit);
int			get_index_in_stack(t_stack *stack, int to_find);
int			get_median_value(t_stack *stack);
void		solve_3_elements(t_info *info);
void		solve_2_elements(t_info *info);
void		free_opelist(t_opelist *elm);
void		free_stack(t_stack *stack);
void		solver_less_than_eq_5(t_info *info);
void		deinit_info(t_info *info);
void		get_max_and_push_to_a(t_info *info);
void		push_to_b_with_limit(t_info *info, int n);
void		push_worker(t_info *info, int limit, int n);
void		smart_rotate(t_info *info, int n);
void		smart_swap(t_info *info, int n);
void		free_array(char **array);
void		exit_error(void);
int			count_elements_in_array(char **array);

#endif

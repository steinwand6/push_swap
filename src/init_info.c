#include "push_swap.h"

void	init_info(t_info *info, int count)
{
	info->a = new_stack();
	if (info->a == NULL)
		exit(1);
	info->b = new_stack();
	if (info->b == NULL)
		exit(1);
	info->opelist = NULL;
	info->count = count - 1;
}

void	add_opelist(t_info *info, const char *op)
{
	t_opelist	*el;
	t_opelist	*new_el;

	el = info->opelist;
	new_el = malloc(sizeof(t_opelist));
	if (new_el == NULL)
		exit(1);
	new_el->op = ft_strdup(op);
	if (el == NULL) {
		info->opelist = new_el;
		return;
	}
	while (el->next)
		el = el->next;
	el->next = new_el;
	new_el->prev = el;
	return ;
}
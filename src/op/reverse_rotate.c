#include "../../includes/push_swap.h"

void	rra(t_data *data, int oui)
{
	t_list	*last;
	t_list	*tmp;

	if (!data->a || !data->a->next)
		return ;
	last = ft_lstlast(data->a);
	tmp = data->a;
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(&data->a, last);
	if (oui)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_data *data, int oui)
{
	t_list	*last;
	t_list	*tmp;

	if (!data->b || !data->b->next)
		return ;
	last = ft_lstlast(data->b);
	tmp = data->b;
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(&data->b, last);
	if (oui)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_putendl_fd("rrr", 1);
}

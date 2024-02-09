#include "../../includes/push_swap.h"

void	pa(t_data *data)
{
	t_list	*tmp;

	if (data->b == NULL)
	{
		return ;
	}
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->a, tmp);
	ft_putendl_fd("pa", 1);
}

void	pb(t_data *data)
{
	t_list	*tmp;

	if (data->a == NULL)
	{
		return ;
	}
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->b, tmp);
	ft_putendl_fd("pb", 1);
}
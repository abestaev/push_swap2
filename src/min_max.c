#include "../includes/push_swap.h"

int	ft_is_sorted(t_data *data)
{
	t_list	*tmp_a;
    t_list  *tmp_b;

	tmp_a = data.a;
    tmp_b = data.b;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
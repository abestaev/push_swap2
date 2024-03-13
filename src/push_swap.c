/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:37:27 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 10:41:11 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	ft_free(t_data *data)
{
	t_list	*tmp;

	while (data->a)
	{
		tmp = data->a->next;
		free(data->a);
		data->a = tmp;
	}
	while (data->b)
	{
		tmp = data->b->next;
		free(data->b);
		data->b = tmp;
	}
}

void	push_b_opti(t_data *data)
{
	ft_index(data);
	ft_cost(data);
	ft_select_node(data);
	ft_select_move(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (1);
	data = ft_init(argc, argv);
	if (data.size_a == 2)
		ft_sort_two(&data, data.a);
	else if (data.size_a == 3)
		ft_sort_three(&data, data.a);
	else if (data.size_a == 5 && ft_is_sorted(data.a) == 1)
		ft_sort_five(&data);
	else if (ft_is_sorted(data.a) == 1)
	{
		pb(&data);
		while (data.a)
			push_b_opti(&data);
		push_a(&data);
	}
	ft_free(&data);
	return (0);
}

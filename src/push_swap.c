/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:37:27 by albestae          #+#    #+#             */
/*   Updated: 2024/02/29 05:43:33 by albestae         ###   ########.fr       */
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
}

static void	ft_sort_two(t_data *data)
{
	if (data->a->content > data->a->next->content)
		sa(data, 1);
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

	data = ft_init(argc, argv);
	if (data.size_a == 2)
		ft_sort_two(&data);
	else if (data.size_a == 3)
		ft_sort_three(&data, data.a);
	else
	{
		pb(&data);
		pb(&data);
		pb(&data);
		ft_sort_three_reverse(&data, data.b);
		while (data.a)
			push_b_opti(&data);
		push_a(&data);
		ft_free(&data);
	}
	return (0);
}

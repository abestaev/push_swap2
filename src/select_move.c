/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:40:02 by albestae          #+#    #+#             */
/*   Updated: 2024/02/29 22:52:06 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_mediane(t_data *data)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = data->a;
	tmp_b = data->b;
	while (tmp_a && tmp_a->index != data->index_a)
		tmp_a = tmp_a->next;
	while (tmp_b && tmp_b->index != data->index_b)
		tmp_b = tmp_b->next;
	if (tmp_a->mediane == 1 && tmp_b->mediane == 1)
		rr(data);
	else if (tmp_a->mediane == 0 && tmp_b->mediane == 0)
		rrr(data);
	else if (tmp_a->mediane == 0 && tmp_b->mediane == 1)
	{
		rra(data, 1);
		rb(data, 1);
	}
	else if (tmp_a->mediane == 1 && tmp_b->mediane == 0)
	{
		ra(data, 1);
		rrb(data, 1);
	}
}

void	ft_best_move_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->a;
	while (tmp && tmp->index != data->index_a)
		tmp = tmp->next;
	if (tmp->mediane == 1)
		ra(data, 1);
	else
		rra(data, 1);
}

void	ft_best_move_b(t_data *data)
{
	t_list	*tmp;

	tmp = data->b;
	while (tmp && tmp->index != data->index_b)
		tmp = tmp->next;
	if (tmp->mediane == 1)
		rb(data, 1);
	else
		rrb(data, 1);
}

void	ft_select_move(t_data *data)
{
	while (data->index_a != 0 || data->index_b != 0)
	{
		if (data->index_a != 0 && data->index_b != 0)
			ft_check_mediane(data);
		else if (data->index_a == 0 && data->index_b != 0)
			ft_best_move_b(data);
		else if (data->index_a != 0 && data->index_b == 0)
			ft_best_move_a(data);
		ft_index(data);
		ft_cost(data);
		ft_select_node(data);
	}
	pb(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:38:45 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:41:44 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_last_rotate(t_data *data, int i, int med);

void	push_a(t_data *data)
{
	int		min;
	int		i;
	t_list	*tmp;

	while (data->b)
		pa(data);
	ft_index_mediane(data->a, data->size_a);
	tmp = data->a;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	tmp = data->a;
	while (tmp->content != min)
		tmp = tmp->next;
	i = tmp->index;
	ft_last_rotate(data, i, tmp->mediane);
}

static void	ft_last_rotate(t_data *data, int i, int med)
{
	if (med == 1)
	{
		while (i != 0)
		{
			ra(data, 1);
			i--;
		}
	}
	else
	{
		while (i != data->size_a)
		{
			rra(data, 1);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:38:01 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:30:56 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_data *data)
{
	t_list	*tmp;

	if (data->b == NULL)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->a, tmp);
	data->size_a++;
	data->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	t_list	*tmp;

	if (data->a == NULL)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->b, tmp);
	data->size_a--;
	data->size_b++;
	write(1, "pb\n", 3);
}

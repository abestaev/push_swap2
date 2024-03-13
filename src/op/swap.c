/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:39:08 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:29:42 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_data *data, int oui)
{
	t_list	*tmp;

	if (data->a && data->a->next)
	{
		tmp = data->a->next;
		data->a->next = tmp->next;
		ft_lstadd_front(&data->a, tmp);
	}
	if (oui)
		write(1, "sa\n", 3);
}

void	sb(t_data *data, int oui)
{
	t_list	*tmp;

	if (data->b && data->b->next)
	{
		tmp = data->b->next;
		data->b->next = tmp->next;
		ft_lstadd_front(&data->b, tmp);
	}
	if (oui)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sb(data, 0);
	sa(data, 0);
	write(1, "ss\n", 3);
}

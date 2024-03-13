/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:38:11 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:31:17 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->a, last);
	if (oui)
		write(1, "rra\n", 4);
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
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(&data->b, last);
	if (oui)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:38:58 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:29:33 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_data *data, int oui)
{
	t_list	*tmp;

	if (!data->a)
	{
		ft_putendl_fd("Error", 1);
		return ;
	}
	tmp = data->a;
	data->a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->a, tmp);
	if (oui)
		write(1, "ra\n", 3);
}

void	rb(t_data *data, int oui)
{
	t_list	*tmp;

	if (!data->b)
		return ;
	tmp = data->b;
	data->b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(&data->b, tmp);
	if (oui)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	write(1, "rr\n", 3);
}

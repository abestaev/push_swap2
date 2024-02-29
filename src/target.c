/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:42:22 by albestae          #+#    #+#             */
/*   Updated: 2024/02/29 05:42:43 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_target_min(t_list *lst)
{
	t_list	*tmp;
	int		min;

	tmp = lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp->content != min)
		tmp = tmp->next;
	if ((tmp->index + 1) == ft_lst_size(lst))
		return (0);
	return (tmp->index + 1);
}

int	ft_get_target_max(t_list *lst)
{
	t_list	*tmp;
	int		max;

	tmp = lst;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp->content != max)
		tmp = tmp->next;
	return (tmp->index);
}

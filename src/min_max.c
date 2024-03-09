/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:36:52 by albestae          #+#    #+#             */
/*   Updated: 2024/03/09 17:11:55 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_min(t_list *lst, int n)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (n > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_max(t_list *lst, int n)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (n < tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

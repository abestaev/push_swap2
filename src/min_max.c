/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:36:52 by albestae          #+#    #+#             */
/*   Updated: 2024/02/26 11:40:04 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//todo: test si y a besoin de tmp
// int	ft_is_sorted(t_data *data)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	tmp_a = data.a;
// 	tmp_b = data.b;
// 	while (tmp && tmp->next)
// 	{
// 		if (tmp->content > tmp->next->content)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

int	ft_is_min(t_list *lst, int n)
{
	t_list *tmp;

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
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (n < tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
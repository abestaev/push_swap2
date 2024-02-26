/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_indexor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:36:59 by albestae          #+#    #+#             */
/*   Updated: 2024/02/26 19:02:37 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_index_mediane(t_list *lst)
{
	t_list *tmp;
	int	i;
	int size;
	
	i = 0;
	size = ft_lst_size(lst);
	tmp = lst;
	while (tmp)
	{
		tmp->index = i;
		if (size - size / 2 > i)
			tmp->mediane = 1;
		else
			tmp->mediane = 0;
		i++;
		tmp = tmp->next;
	}
}

void	ft_index(t_data *data)
{
	ft_index_mediane(data->a);
	ft_index_mediane(data->b);
	data->size_a = ft_lst_size(data->a);
	data->size_b = ft_lst_size(data->b);
}


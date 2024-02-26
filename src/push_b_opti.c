/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:31:10 by albestae          #+#    #+#             */
/*   Updated: 2024/02/26 12:10:57 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b_opti(t_data *data)
{
	ft_index(data);
	ft_cost(data);
	// pb(data);
	// ft_index(data);
	// ft_cost(data);
}

// si n n'est pas le new MIN or MAX
static int	ft_get_target(t_list *lst, int n)
{
	t_list	*tmp;

	tmp = lst;
	if (n > lst->content && n < ft_lstlast(lst)->content)
		return (0);
	while (lst && lst->next)
	{
		if (n < lst->content && n > lst->next->content)
			return (lst->next->index);
		lst = lst->next;
	}
	return (-666666);
}

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
	return (tmp->index);
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

static void	ft_get_target_cost(t_data *data)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = data->a;
	tmp_b = data->b;
	
	while (tmp_a)
	{
		if (ft_is_min(tmp_b, tmp_a->content))
		{
			printf("MIN\n");
			tmp_a->target = ft_get_target_min(tmp_b);
		}
		else if (ft_is_max(tmp_b, tmp_a->content))
		{
			printf("MAX\n");
			tmp_a->target = ft_get_target_max(tmp_b);
		}
		else
		{
			printf("NORMAL\n");
			tmp_a->target = ft_get_target(tmp_b, tmp_a->content);
		}
		tmp_a = tmp_a->next;
	}
}

static void	ft_on_top(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->mediane == 1)
			tmp->cost = tmp->index;
		else
			tmp->cost = ft_lst_size(lst) - tmp->index;
		tmp = tmp->next;
	}
}

void	ft_cost(t_data *data)
{
	ft_get_target_cost(data);
	ft_on_top(data->a);
}
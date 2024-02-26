/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:31:10 by albestae          #+#    #+#             */
/*   Updated: 2024/02/26 20:05:30 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b_opti(t_data *data)
{
	ft_index(data);
	ft_cost(data);
	ft_select_node(data);
	ft_select_move(data);
}

void 	ft_check_mediane(t_data *data)
{
	
}

void	ft_select_move(t_data *data)
{
	while (data->index_a != 0 && data->index_b != 0)
	{
		if (data->index_a != 0 && data->index_b != 0)
			ft_check_mediane(data);
		else if (data->index_a == 0 && data->index_b != 0)
			ft_best_move_a();
		else if (data->index_a != 0 && data->index_b == 0)
			ft_best_move_b();
	}
	pb(data);
}

void	ft_select_node(t_data *data)
{
	int		min_cost;
	t_list	*tmp;

	tmp = data->a;
	min_cost = tmp->cost;
	while (tmp)
	{
		if (min_cost > tmp->cost)
			min_cost = tmp->cost;
		tmp = tmp->next;
	}
	tmp = data->a;
	while (tmp)
	{
		if (tmp->cost == min_cost)
		{
			data->index_a = tmp->index;
			data->index_b = tmp->target;
			break ;
		}
		tmp = tmp->next;
	}
	printf("MIN COST = %d     [index_a]=%d [index_b]=%d\n", min_cost,
		data->index_a, data->index_b);
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
//VERIFIER SI LA FONCTION MARCHE CORRECTEMENT /!\ SOURCE D'ERREUR POSSIBLE /!\.
void	ft_cost(t_data *data)
{
	t_list *tmp_a;
	t_list *tmp_b;

	ft_get_target_cost(data);
	ft_on_top(data->a);
	tmp_a = data->a;
	while (tmp_a)
	{
		tmp_b = data->b;
		while (tmp_b->index != tmp_a->target)
			tmp_b = tmp_b->next;
		if (tmp_b->mediane == 1)
			tmp_a->cost += tmp_a->target;
		else
			tmp_a->cost = tmp_a->cost + data->size_b - tmp_a->target; 
		tmp_a = tmp_a->next;
	}
}
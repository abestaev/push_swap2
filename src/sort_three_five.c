/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:37:37 by albestae          #+#    #+#             */
/*   Updated: 2024/03/09 21:46:54 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three_reverse(t_data *data, t_list *lst)
{
	int	a;
	int	b;
	int	c;

	a = lst->content;
	b = lst->next->content;
	c = lst->next->next->content;
	if (a > c && a > b && c > b)
	{
		rrb(data, 1);
		sb(data, 1);
	}
	if (b > c && b > a && c > a)
		rb(data, 1);
	if (b > c && b > a && a > c)
		sb(data, 1);
	if (c > a && c > b && a > b)
		rrb(data, 1);
	if (c > b && b > a)
	{
		sb(data, 1);
		rrb(data, 1);
	}
}

void	ft_sort_three(t_data *data, t_list *lst)
{
	int	a;
	int	b;
	int	c;

	a = lst->content;
	b = lst->next->content;
	c = lst->next->next->content;
	if (a < b && b > c && a < c)
	{
		rra(data, 1);
		sa(data, 1);
	}
	else if (a > b && b < c && a > c)
		ra(data, 1);
	else if (a > b && b > c)
	{
		ra(data, 1);
		sa(data, 1);
	}
	else if (a < b && b > c && a > c)
		rra(data, 1);
	else if (a > b && b < c && a < c)
		sa(data, 1);
}

void	ft_sort_two(t_data *data, t_list *lst)
{
	if (lst->content > lst->next->content)
		sa(data, 1);
}

static void	ft_push_max(t_data *data)
{
	int		max;
	t_list	*tmp;

	tmp = data->a;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	if (data->a->content == max)
	{
		ra(data, 1);
		pb(data);
	}
	else
		pb(data);
}

void	ft_sort_five(t_data *data)
{
	ft_push_max(data);
	ft_push_max(data);
	ft_sort_three(data, data->a);
	while (data->b)
	{
		if (ft_is_min(data->a, data->a->content)
			&& data->a->content > data->b->content)
			pa(data);
		else if (ft_is_max(data->a, data->b->content) && ft_is_max(data->a,
				data->a->content)
			&& data->b->content > ft_lstlast(data->a)->content)
		{
			pa(data);
			sa(data, 1);
		}
		else if (data->a->content > data->b->content
			&& data->b->content > ft_lstlast(data->a)->content)
			pa(data);
		else
			ra(data, 1);
	}
	push_a(data);
}

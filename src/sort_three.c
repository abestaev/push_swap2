/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:37:37 by albestae          #+#    #+#             */
/*   Updated: 2024/02/20 19:37:37 by albestae         ###   ########.fr       */
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

void	ft_sort_two(t_data *data)
{
	if (data->a->content > data->a->next->content)
		sa(data, 1);
}

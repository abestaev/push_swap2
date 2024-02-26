/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:37:27 by albestae          #+#    #+#             */
/*   Updated: 2024/02/26 11:59:00 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_list *tmp;
	t_list *tmp2;

	data = ft_init(argc, argv);

	tmp = data.a;
	printf("list_a : ");
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	pb(&data);
	pb(&data);
	pb(&data);
	

	printf("\n");
	ft_sort_three_reverse(&data, data.b);
	tmp = data.b;
	// printf("list_b : ");
	// while (tmp)
	// {
	// 	printf("[%d] ", tmp->content);
	// 	tmp = tmp->next;
	// }
	printf("\n");
	// while (ft_is_sorted(data.a) && ft_lst_size(data.a) > 3)
	push_b_opti(&data);

	tmp = data.a;
	tmp2 = data.b;
	printf("[LIST A]                	[LIST B]\n");
	while (tmp || tmp2)
	{
		if (tmp)
		{
			printf("[%d] i=%d med=%d cost=%d target=%d   ", 
			tmp->content, tmp->index, tmp->mediane, tmp->cost, tmp->target);
		tmp = tmp->next;
		}
		else 
			printf("				");
		if (tmp2)
		{
			printf("[%d] i=%d med=%d cost=%d target=%d\n", 
			tmp2->content, tmp2->index, tmp2->mediane, tmp2->cost, tmp2->target);
			tmp2 = tmp2->next;
		}
		else 
			printf("\n");
	}
	return (0);
}

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_list *tmp;

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
	
	//while(&data.size_a > 2)
	//pb_opti(&data);


	

	printf("\n");
	tmp = data.b;
	printf("list_b : ");
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	ft_sort_three_reverse(&data, data.b);
	tmp = data.b;
	printf("list_b : ");
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	
	ft_sort_three(&data, data.a);
	pa(&data);
	pa(&data);
	pa(&data);
	tmp = data.a;
	printf("list_a : ");
	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
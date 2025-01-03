/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:42:07 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 03:46:03 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = s;
	while (n > 0)
	{
		*t++ = '\0';
		n--;
	}
}

static void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

t_data	ft_init(int argc, char **argv)
{
	t_data	data;
	t_list	*new;
	char	**tab;
	int		i;

	tab = ft_parsing(argc, argv);
	i = 0;
	ft_bzero(&data, sizeof(data));
	while (tab[i])
	{
		new = ft_lstnew(ft_atoi(tab[i]));
		if (new == NULL)
			exit(1);
		ft_lstadd_back(&(data.a), new);
		i++;
	}
	data.b = NULL;
	data.size_b = 0;
	data.size_a = ft_lst_size(data.a);
	if (argc == 2)
		ft_free_split(tab);
	free(tab);
	return (data);
}

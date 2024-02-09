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
			exit (1);
		ft_lstadd_back(&(data.a), new);
		i++;
	}
    data.b = NULL;
	free(tab);
	return (data);
}
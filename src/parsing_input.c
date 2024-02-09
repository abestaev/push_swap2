#include "../includes/push_swap.h"


int	ft_check_args(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_onlydigit(tab[i]))
			ft_error("Error: Not only digit", tab);
		if (ft_check_size(tab[i]))
			ft_error("Error: Bigger than int", tab);
		i++;
	}
	if (ft_check_doublons(tab))
		ft_error("Error: Multiple occurences", tab);
	return (0);
}

void	ft_error(char *str, char **tab)
{
	free(tab);
	ft_putendl_fd(str, 2);
	exit(1);
}

char	**ft_parsing(int argc, char **argv)
{
	char	**tab;
	int		i;

    if (argc == 2)
        tab = ft_split(argv[1], ' ');
    else
    {
        tab = malloc(sizeof(char *) * argc);
        if (tab == NULL)
            return (NULL);
        i = 0;
        while (i < argc - 1)
		{
            tab[i] = argv[1 + i];
			i++;
		}
        tab[i] = NULL;   
    }
    ft_check_args(tab);
	return (tab);
}
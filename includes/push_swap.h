#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				cost;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
}					t_data;

void				sa(t_data *data, int oui);
void				sb(t_data *data, int oui);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data, int oui);
void				rb(t_data *data, int oui);
void				rr(t_data *data);
void				rra(t_data *data, int oui);
void				rrb(t_data *data, int oui);
void				rrr(t_data *data);

int					ft_strlen(const char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int value);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *nptr);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				**ft_parsing(int argc, char **argv);
void				ft_error(char *str, char **tab);
int					ft_check_args(char **tab);
int					ft_onlydigit(char *str);
int					ft_check_doublons(char **tab);
int					ft_check_size(char *str);
char				*ft_clean(char *str);

t_data				ft_init(int argc, char **argv);


void    ft_sort_three_reverse(t_data *data, t_list *lst);
void    ft_sort_three(t_data *data, t_list *lst);
void    ft_sort_two(t_data *data);

#endif
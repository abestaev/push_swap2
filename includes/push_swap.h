/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:37:09 by albestae          #+#    #+#             */
/*   Updated: 2024/03/13 04:23:13 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct s_list
{
	int				content;
	int				cost;
	int				index;
	int				mediane;
	int				target;
	int				min;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	int				size_a;
	int				size_b;
	int				index_a;
	int				index_b;
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
int					ft_lst_size(t_list *lst);
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

void				ft_sort_three_reverse(t_data *data, t_list *lst);
void				ft_sort_three(t_data *data, t_list *lst);

int					ft_is_sorted(t_list *lst);
void				push_b_opti(t_data *data);
void				ft_index(t_data *data);
void				ft_cost(t_data *data);
int					ft_is_min(t_list *lst, int n);
int					ft_is_max(t_list *lst, int n);
void				ft_select_node(t_data *data);
void				ft_select_move(t_data *data);
void				ft_check_mediane(t_data *data);
void				ft_best_move_a(t_data *data);
void				ft_best_move_b(t_data *data);
void				push_a(t_data *data);
void				ft_index_mediane(t_list *lst, int size);
void				push_b_opti(t_data *data);
void				ft_on_top(t_list *lst);
void				ft_get_target_cost(t_data *data);
int					ft_get_target(t_list *lst, int n);
int					ft_get_target_min(t_list *lst);
int					ft_get_target_max(t_list *lst);
void				ft_cost(t_data *data);
void				ft_sort_two(t_data *data, t_list *lst);
void				ft_sort_five(t_data *data);

#endif

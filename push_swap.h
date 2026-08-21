#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}	t_stack;

char	**ft_split(char const *s, char c);
void	free_tokens(char **tokens);
int		count_total_elements(int argc, char **argv);
int		ft_atoi_safe(char *str, int *result);
int		parse_args(int argc, char **argv, t_stack *stack);

t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_stack(t_stack *a, t_stack *b);

#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_operation;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
	int			count[11];
	int			disorder;
	t_strategy	strat;
	t_strategy	used;
	int			bench;
}	t_ps;

char		**ft_split(char const *s, char c);
void		free_tokens(char **tokens);
int			count_total_elements(int argc, char **argv);
int			ft_atoi_safe(char *str, int *result);
int			parse_args(int argc, char **argv, t_stack *stack);

t_strategy	parse_strategy_flag(const char *flag);
int			parse_config(int argc, char **argv, t_config *config);

t_stack		*init_stack(int capacity);
void		free_stack(t_stack *stack);
int			has_duplicates(t_stack *stack);
int			is_sorted(t_stack *stack);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		sort_stack(t_stack *a, t_stack *b);

void		print_bench(t_ps *ps);
const char	*op_name(int operation);

#endif

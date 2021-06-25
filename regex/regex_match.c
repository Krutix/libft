#include "__ft_regex.h"
#include "ft_algorithm.h"
#include "stdio.h"

static void	branch_travel(t_regex *re, uint16_t ch, uint16_t start_idx, t_vector *out_states)
{
	t_regex_state *state;

	if (start_idx == REGEX_NONE_STATE)
		return ;
	state = ft_vec_at(&re->__states, start_idx);
	if (state->c == ch)
		ft_vec_push_back(out_states, &start_idx);
	else if (state->c == e_re_code_split)
	{
		branch_travel(re, ch, state->out1, out_states);
		branch_travel(re, ch, state->out2, out_states);
	}
	else if (!(ch & ~255)
		&& (((state->c & REPOST_CHARSET) && ft_strchr(*(char**)ft_vec_at(
			&re->__charsets, state->c & 255), ch) != NULL)
		|| ((state->c & REPOST_INVCHARSET) && ft_strchr(*(char**)ft_vec_at(
			&re->__charsets, state->c & 255), ch) == NULL)))
		ft_vec_push_back(out_states, &start_idx);
}

static void	step(t_regex *re, uint16_t ch, t_vector *prev_states, t_vector *out_states)
{
	t_regex_state *state;

	out_states->size = 0;
	for (size_t i = 0; i < prev_states->size; i++)
	{
		state = ft_vec_at(&re->__states, *(uint16_t*)ft_vec_at(prev_states, i));
		branch_travel(re, ch, state->out1, out_states);
		branch_travel(re, ch, state->out2, out_states);
	}
}

t_bool	ft_regex_match(t_regex *re, char const *str)
{
	t_vector	prev_states;
	t_vector	curr_states;
	uint16_t	v;

	ft_vec_construct(&prev_states, sizeof(uint16_t));
	ft_vec_construct(&curr_states, sizeof(uint16_t));
	v = 0;
	ft_vec_push_back(&prev_states, &v);
	while (*str)
	{
		step(re, *str, &prev_states, &curr_states);
		ft_swap_n(&prev_states, &curr_states, sizeof(t_vector));
		str++;
	}
	step(re, e_re_code_end, &prev_states, &curr_states);
	v = !!curr_states.size;
	ft_vec_destructor(&prev_states, NULL);
	ft_vec_destructor(&curr_states, NULL);
	return v;
}
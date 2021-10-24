#include "__ft_regex.h"
#include "ft_algorithm.h"
#include "stdio.h"

static void branch_travel(t_regex *re, t_rechar ch, state_id start_idx, t_vector *out_states)
{
	t_regex_state *state;

	if (start_idx == REGEX_NONE_STATE)
		return;
	state = ft_vec_at(&re->__states, start_idx);
	if (state->state == restate_end && ch == rechar_end)
		ft_vec_push_back(out_states, &start_idx);
	else if (state->state == restate_split)
	{
		branch_travel(re, ch, state->out1, out_states);
		branch_travel(re, ch, state->out2, out_states);
	}
	else if (chenum_is(&state->chenum, ch) == ft_true)
		ft_vec_push_back(out_states, &start_idx);
}

static void step(t_regex *re, t_rechar ch, t_vector *prev_states, t_vector *out_states)
{
	t_regex_state *state;

	out_states->size = 0;
	for (size_t i = 0; i < prev_states->size; i++)
	{
		state = ft_vec_at(&re->__states, *(state_id *)ft_vec_at(prev_states, i));
		branch_travel(re, ch, state->out1, out_states);
		branch_travel(re, ch, state->out2, out_states);
	}
}

t_ft_err	ft_regex_match(t_regex *re, char const *str)
{
	t_vector	prev_states;
	t_vector	curr_states;
	t_ft_err	v;

	ft_vec_construct(&prev_states, sizeof(state_id));
	ft_vec_construct(&curr_states, sizeof(state_id));
	ft_vec_push_back(&prev_states, "\0\0");
	while (*str)
	{
		step(re, *str, &prev_states, &curr_states);
		ft_swap_n(&prev_states, &curr_states, sizeof(t_vector));
		str++;
	}
	step(re, rechar_end, &prev_states, &curr_states);
	v = ft_err_ok;
	if (curr_states.size == 0)
		v = ft_err_fail;
	ft_vec_destructor(&prev_states, NULL);
	ft_vec_destructor(&curr_states, NULL);
	return (v);
}
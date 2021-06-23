#include "__ft_regex.h"
#include "ft_list.h"
#include "stdio.h"

static void	set_next(t_regex *re, t_list *l_ptr, uint16_t next_value)
{
	t_regex_state	*state_ptr;

	for (; l_ptr; l_ptr = l_ptr->next)
	{
		state_ptr = ft_vec_at(&re->__states, (t_ullint)l_ptr->data);
		if (state_ptr->out1 == REGEX_NONE_STATE)
			state_ptr->out1 = next_value;
	}
}

static void push_state(t_regex *re, t_vector *frag_stack, t_regex_state state)
{
	t_list	*l_ptr;

	ft_vec_push_back(&re->__states, &state);
	l_ptr = ft_create_list((void*)re->__states.size - 1);
	ft_vec_push_back(frag_stack, &l_ptr);
}

static void	concat_last(t_regex *re, t_vector *frag_stack)
{
	t_list			*l_ptr;
	t_list			*r_ptr;

	l_ptr = *(t_list**)ft_vec_at(frag_stack, frag_stack->size - 2);
	r_ptr = *(t_list**)ft_vec_at(frag_stack, frag_stack->size - 1);
	set_next(re, l_ptr, (t_ullint)r_ptr->data);
	ft_list_merge(&l_ptr, r_ptr);
	ft_vec_pop_back(frag_stack, NULL);
}

static void split_last(t_regex *re, t_vector *frag_stack)
{
	t_regex_state	state;
	t_list			*l_ptr;
	t_list			*r_ptr;

	l_ptr = *(t_list**)ft_vec_at(frag_stack, frag_stack->size - 2);
	r_ptr = *(t_list**)ft_vec_at(frag_stack, frag_stack->size - 1);
	state = (t_regex_state) \
		{ e_rep_op_code_split, (t_ullint)l_ptr->data, (t_ullint)r_ptr->data };
	ft_vec_push_back(&re->__states, &state);
	ft_list_merge(&l_ptr, r_ptr);
	ft_vec_pop_back(frag_stack, NULL);
	r_ptr = ft_create_list((void *)re->__states.size - 1);
	ft_list_merge(&r_ptr, l_ptr);
	ft_vec_pop_back(frag_stack, NULL);
	ft_vec_push_back(frag_stack, &r_ptr);
}

t_bool	ft_post2nfa(t_regex *re, t_re_post *post_re)
{
	t_vector		frag_stack; // dont destroyed

	ft_vec_construct(&frag_stack, sizeof(t_list *));
	ft_vec_construct(&re->__states, sizeof(t_regex_state));
	push_state(re, &frag_stack, (t_regex_state) \
		{ e_rep_op_code_start, REGEX_NONE_STATE, REGEX_NONE_STATE });
	while (*post_re)
	{
		switch (*post_re)
		{
			case e_rep_op_code_split:
				split_last(re, &frag_stack);
				break;
			case e_rep_op_code_concat:
				concat_last(re, &frag_stack);
				break;
			default:
				push_state(re, &frag_stack, (t_regex_state) \
					{ *post_re, REGEX_NONE_STATE, REGEX_NONE_STATE });
				break;
		}
		post_re++;
	}
	concat_last(re, &frag_stack);
	push_state(re, &frag_stack, (t_regex_state) \
		{ e_rep_op_code_end, REGEX_NONE_STATE, REGEX_NONE_STATE });
	concat_last(re, &frag_stack);
	ft_list_clear(ft_vec_front(&frag_stack), NULL);
	return t_true;
}

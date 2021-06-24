#ifndef __FT_REGEX_H
# define __FT_REGEX_H

# include "ft_regex.h"

enum e_rep_type
{
    e_rep_type_invalid = 0,
    e_rep_type_symbol,
    e_rep_type_bracket_open,
    e_rep_type_bracket_close,
    e_rep_type_operand,
    e_rep_type_post_operand
};

# define REPOST_OPERAND     (512)

enum e_rep_op_code
{
    e_rep_op_code_start     =   1   | REPOST_OPERAND,
    e_rep_op_code_end       =   2   | REPOST_OPERAND,
    e_rep_op_code_concat    =   '^' | REPOST_OPERAND,
    e_rep_op_code_split     =   '|' | REPOST_OPERAND,
    e_rep_op_code_one_multy =   '+' | REPOST_OPERAND,
    e_rep_op_code_multy     =   '*' | REPOST_OPERAND,
    e_rep_op_code_one_zero  =   '?' | REPOST_OPERAND
};

#define     REP_CONCAT_CELL (t_rep_cell){ e_rep_op_code_concat, e_rep_type_operand, 1 }

typedef struct
{
    uint16_t    code;
    char        type;
    uint8_t     prior;
}       t_rep_cell;

typedef  uint16_t   t_re_post;

typedef struct s_re_post_buffer
{
    t_re_post    buf[1024];
    t_re_post    *ptr;
}   t_re_post_buffer;

typedef struct s_rep_cell_stack
{
    t_rep_cell          stack[1024];
    t_rep_cell          *ptr;
}   t_rep_cell_stack;

typedef uint16_t state_id;
# define REGEX_NONE_STATE UINT16_MAX

typedef struct s_regex_state
{
    int32_t     c;
    state_id    out1;
    state_id    out2;
}       t_regex_state;

t_re_post       *ft_re2post(char const *re);
t_rep_cell      *ft_re2reir(char const *re);
t_bool	        ft_post2nfa(t_regex *re, t_re_post *post_re);

#endif
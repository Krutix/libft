#ifndef __FT_REGEX_H
# define __FT_REGEX_H

# include "__charenum.h"
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

# define REPOST_VALUE       ((1 << 8) - 1)
# define REPOST_OPERAND     ((1 << 8))
# define REPOST_CHARSET     ((1 << 9))
# define REPOST_INVCHARSET  ((1 << 10) | REPOST_CHARSET)

enum e_rep_op_code
{
    e_re_code_start     =   1   | REPOST_OPERAND,
    e_re_code_end       =   2   | REPOST_OPERAND,
    e_re_code_concat    =   '^' | REPOST_OPERAND,
    e_re_code_split     =   '|' | REPOST_OPERAND,
    e_re_code_one_multy =   '+' | REPOST_OPERAND,
    e_re_code_multy     =   '*' | REPOST_OPERAND,
    e_re_code_one_zero  =   '?' | REPOST_OPERAND,
    e_re_code_any       =   0   | REPOST_INVCHARSET,
    e_re_code_space     =   1   | REPOST_CHARSET,
    e_re_code_nspace    =   1   | REPOST_INVCHARSET,
    e_re_code_digit     =   2   | REPOST_CHARSET,
    e_re_code_ndigit    =   2   | REPOST_INVCHARSET,
    e_re_code_octal     =   3   | REPOST_CHARSET,
    e_re_code_noctal    =   3   | REPOST_INVCHARSET,
    e_re_code_hex       =   4   | REPOST_CHARSET,
    e_re_code_nhex      =   4   | REPOST_INVCHARSET,
};

#define     REP_CONCAT_CELL (t_rep_cell){ e_re_code_concat, e_rep_type_operand, 1 }

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

enum restate {
    restate_none,
    restate_split,
    restate_start,
    restate_end
};
typedef int8_t t_restate;

enum rechar {
    rechar_end = 127,
};
typedef int16_t t_rechar;

typedef struct s_regex_state
{
    t_chenum    chenum;
    state_id    out1;
    state_id    out2;
    t_restate   state;
}       t_regex_state;

t_re_post       *ft_re2post(char const *re);
t_rep_cell      *ft_re2reir(char const *re);
t_bool          ft_post2nfa(t_regex *re, t_re_post *post_re);

#endif

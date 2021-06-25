#include "__ft_regex.h"

static uint8_t  operand_prior(char op)
{
    if (ft_strchr("()", op) != NULL)
        return (255);
    if (ft_strchr("|", op) != NULL)
        return (2);
    if (ft_strchr("*+?", op) != NULL)
        return (1);
    return (0);
}

t_rep_cell     read_slesh_cell(char const **re)
{
    char    ch;

    ch = *((*re)++);
    if (ft_strchr("+*?|().", ch) != NULL)
        return ((t_rep_cell){ch, e_rep_type_symbol, 0});
    if (ch == 's')
        return ((t_rep_cell){e_re_code_space, e_rep_type_symbol, 0});
    if (ch == 'S')
        return ((t_rep_cell){e_re_code_nspace, e_rep_type_symbol, 0});
    if (ch == 'd')
        return ((t_rep_cell){e_re_code_digit, e_rep_type_symbol, 0});
    if (ch == 'D')
        return ((t_rep_cell){e_re_code_ndigit, e_rep_type_symbol, 0});
    if (ch == 'o')
        return ((t_rep_cell){e_re_code_octal, e_rep_type_symbol, 0});
    if (ch == 'O')
        return ((t_rep_cell){e_re_code_noctal, e_rep_type_symbol, 0});
    if (ch == 'x')
        return ((t_rep_cell){e_re_code_hex, e_rep_type_symbol, 0});
    if (ch == 'X')
        return ((t_rep_cell){e_re_code_nhex, e_rep_type_symbol, 0});
    return ((t_rep_cell){ch, e_rep_type_symbol, 0});
}

t_rep_cell     read_cell(char const **re)
{
    char    ch;

    ch = *((*re)++);
    if (ft_strchr("+*?", ch) != NULL)
        return ((t_rep_cell){ch | REPOST_OPERAND,
            e_rep_type_post_operand, operand_prior(ch)});
    if (ft_strchr("|", ch) != NULL)
        return ((t_rep_cell){ ch | REPOST_OPERAND,
            e_rep_type_operand, operand_prior(ch)});
    if (ft_strchr("(", ch) != NULL)
        return ((t_rep_cell){ ch,
            e_rep_type_bracket_open, operand_prior(ch)});
    if (ch == '.')
        return ((t_rep_cell){e_re_code_any, e_rep_type_symbol, 0});
    if (ft_strchr(")", ch) != NULL)
        return ((t_rep_cell){ '(',
            e_rep_type_bracket_close, operand_prior(ch)});
    if (ch == '\\')
        return (read_slesh_cell(re));
    return ((t_rep_cell){ch, e_rep_type_symbol, 0});
}

t_rep_cell  *ft_re2reir(char const *re)
{
    static t_rep_cell_stack reir;
    t_bool                  set_concat;
    t_rep_cell              c;

    reir.ptr = reir.stack;
    set_concat = 0;
    while (*re)
    {
        c = read_cell(&re);
        if (c.type == e_rep_type_symbol)
        {
            if (set_concat == t_true)
                *(reir.ptr++) = REP_CONCAT_CELL;
            set_concat = t_true;
        }
        else if (c.type == e_rep_type_bracket_open)
        {
            if (set_concat == t_true)
                *(reir.ptr++) = REP_CONCAT_CELL;
            set_concat = t_false;
        }
        else if (c.type == e_rep_type_bracket_close)
            set_concat = t_true;
        else if (c.type == e_rep_type_operand)
            set_concat = t_false;
        *(reir.ptr++) = c;
    }
    *reir.ptr = (t_rep_cell){ 0, e_rep_type_invalid, 0 };
    return reir.stack;
}
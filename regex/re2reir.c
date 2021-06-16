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

t_rep_cell     read_cell(char const *re)
{
    if (ft_strchr("+*?", *re) != NULL)
        return ((t_rep_cell){
            *re | REPOST_OPERAND, e_rep_type_post_operand,
            operand_prior(*re)});
    if (ft_strchr("|", *re) != NULL)
        return ((t_rep_cell){
            *re | REPOST_OPERAND, e_rep_type_operand,
            operand_prior(*re)});
    if (ft_strchr("(", *re) != NULL)
        return ((t_rep_cell){
            *re, e_rep_type_bracket_open,
            operand_prior(*re)});
    if (ft_strchr(")", *re) != NULL)
        return ((t_rep_cell){
            '(', e_rep_type_bracket_close, operand_prior(*re)});
    return ((t_rep_cell){
        *re, e_rep_type_symbol, 0});
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
        c = read_cell(re);
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
        re++;
    }
    *reir.ptr = (t_rep_cell){ 0, e_rep_type_invalid, 0 };
    return reir.stack;
}
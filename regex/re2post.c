#include "__ft_regex.h"

void  pop_op_stack(t_re_post_buffer *buf, t_rep_cell_stack *post_op, int prior)
{
    while (post_op->stack < post_op->ptr && post_op->ptr->prior <= prior)
        *(buf->ptr++) = (post_op->ptr--)->code;
}

void  pop_op_stack_bracket(t_re_post_buffer *buf, t_rep_cell_stack *post_op)
{
    while (post_op->ptr->type != e_rep_type_bracket_open)
        *(buf->ptr++) = (post_op->ptr--)->code;
    post_op->ptr--;
}

t_re_post   *ft_re2post(char const *re)
{
    static t_re_post_buffer buf;
    t_rep_cell_stack        op_stack;
    t_rep_cell              *reir;

    buf.ptr = buf.buf;
    op_stack.ptr = op_stack.stack;
    reir = ft_re2reir(re);
    while (reir->type != e_rep_type_invalid)
    {
        if (reir->type == e_rep_type_symbol
            || reir->type == e_rep_type_post_operand)
            *(buf.ptr++) = reir->code;
        else if (reir->type == e_rep_type_bracket_open)
            *(++op_stack.ptr) = *reir;
        else if (reir->type == e_rep_type_bracket_close)
            pop_op_stack_bracket(&buf, &op_stack);
        else
        {
            pop_op_stack(&buf, &op_stack, reir->prior);
            *(++op_stack.ptr) = *reir;
        }
        reir++;
    }
    pop_op_stack(&buf, &op_stack, 255);
    *buf.ptr = 0;
    return (buf.buf);
}

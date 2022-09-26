#include "ftst.h"
#include "ft_list.h"

TEST(ft_list_at)
{
    t_list* head = NULL;
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)110)), "malloc error");

    EQ(ft_list_at(head, 0)->data, (void*)110, p);
    EQ(ft_list_at(head, 1)->data, (void*)220, p);
    EQ(ft_list_at(head, 2)->data, (void*)330, p);

    EQ(ft_list_at(NULL, 2), NULL, p);

    ft_list_clear(head, NULL);
}

TEST(ft_list_size)
{
    t_list* head = NULL;
    EQ(ft_list_size(head), 0);

    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)330)), "malloc error");
    EQ(ft_list_size(head), 1);

    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)220)), "malloc error");
    EQ(ft_list_size(head), 2);

    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)110)), "malloc error");
    EQ(ft_list_size(head), 3);

    ft_list_clear(head, NULL);
} 

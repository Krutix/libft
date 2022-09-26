#include "ftst.h"
#include "ft_dlist.h"

TEST(ft_dlist_at)
{
    t_dlist* head = NULL;
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");

    EQ(ft_list_at((t_list*)head, 0)->data, (void*)110, p);
    EQ(ft_list_at((t_list*)head, 1)->data, (void*)220, p);
    EQ(ft_list_at((t_list*)head, 2)->data, (void*)330, p);

    EQ(ft_list_at(NULL, 2), NULL, p);

    ft_list_clear((t_list*)head, NULL);
}

TEST(ft_dlist_size)
{
    t_dlist* head = NULL;
    EQ(ft_list_size((t_list*)head), 0);

    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    EQ(ft_list_size((t_list*)head), 1);

    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), "malloc error");
    EQ(ft_list_size((t_list*)head), 2);

    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");
    EQ(ft_list_size((t_list*)head), 3);

    ft_list_clear((t_list*)head, NULL);
} 

#include "ftst.h"
#include "ft_dlist.h"

static int cmp(void *l, void *r)
{
    return l - r;
}

static void debug(void*p)
{
    printf("%lli | ", (long long)p);
}

TEST(ft_dlist_sort)
{
    t_dlist* head = NULL;
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    ft_dlist_sort(&head, NULL, NULL, cmp);
    NE(head, NULL, p, ASSERT);
    EQ((long long)head->data, 110, lli);
    NE(head->next, NULL, p, ASSERT);
    EQ((long long)head->next->data, 220, lli);
    NE(head->next->next, NULL, p, ASSERT);
    EQ((long long)head->next->next->data, 330, lli);
    RUNTIME_ASSERT(ft_dlist_push_back(&head, ft_create_dlist((void*)150)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)150)), "malloc error");
    ft_dlist_sort(&head, NULL, NULL, cmp);
    EQ((long long)head->next->data, 150, lli);
    //ft_list_foreach((t_list*)head, debug);
}

TEST(ft_dlist_sort_insert)
{
    t_dlist* head = NULL;
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");

    ft_dlist_sort_insert(&head, ft_create_dlist((void*)200), &cmp);
    EQ(head->data, (void*)110, p);
    EQ(head->next->data, (void*)200, p);
    EQ(head->next->prev, head, p);
    EQ(head->next->next->data, (void*)220, p);
    ft_dlist_sort_insert(&head, ft_create_dlist((void*)100), &cmp);
    EQ(head->data, (void*)100, p);
    EQ(head->next->data, (void*)110, p);
}

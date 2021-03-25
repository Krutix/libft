#include "ft_dlist.h"
#define FTST_MALLOC_TEST 1
#include "ftst.h"

#include "stdlib.h"
#include "string.h"

TEST(ft_create_dlist_i)
{
    char buffer[256];

    t_dlist* list = ft_create_dlist_i(sizeof(buffer));

    EQ(MALLOC_SIZE(list), sizeof(t_dlist) + sizeof(buffer), zu);

    NE(list, NULL, p, ASSERT);

    EQ(list->data, ((void*)list) + sizeof(t_dlist), p);
    EQ(list->next, NULL, p);

    char test_buffer[sizeof(t_dlist) + sizeof(buffer)];
    bzero(test_buffer, sizeof(t_dlist) + sizeof(buffer));

    IS_FALSE(memcmp(((void*)list) + sizeof(t_dlist), test_buffer, sizeof(buffer)));
    IS_FALSE(memcmp(list->data, test_buffer, sizeof(buffer)));

    free(list);

}

TEST(ft_create_dlist)
{
    typedef struct {
        char buffer[256];
    } t_test;
    t_dlist* list = ft_create_dlist((void*)999);

    EQ(MALLOC_SIZE(list), sizeof(t_dlist), zu);

    NE(list, NULL, p, ASSERT);

    EQ(list->data, (void*)999, p);
    EQ(list->next, NULL, p);

    free(list);
}

TEST(ft_dlist_push_front)
{
    t_dlist* head = NULL;

    IS_TRUE(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), i, ASSERT);
    NE(head, NULL, p, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, NULL, p);
    EQ(head->prev, NULL, p);
    t_dlist* tbh = head;
    IS_TRUE(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), i, ASSERT);
    EQ(head->data, (void*)110, p);
    EQ(head->prev, NULL, p);
    EQ(head->next, tbh, p);
    EQ(head->next->next, NULL, p);
    EQ(head->next->data, (void*)220, p);
    NE(head->next->prev, NULL, p, ASSERT);
    EQ(head->next->prev->data, (void*)110, p);

    MALLOC_LIMIT_SET(0);
    IS_FALSE(ft_dlist_push_front(&head, tbh = ft_create_dlist(NULL)));
    MALLOC_LIMIT_CLEAN();

    free(head->next);
    free(head);
}

TEST(ft_dlist_push_back)
{
    t_dlist* head = NULL;

    IS_TRUE(ft_dlist_push_back(&head, ft_create_dlist((void*)220)), i, ASSERT);
    NE(head, NULL, p, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, NULL, p);
    t_dlist* tbh;
    IS_TRUE(ft_dlist_push_back(&head, tbh = ft_create_dlist((void*)110)), i, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, tbh, p);
    EQ(head->next->next, NULL, p);
    EQ(head->next->data, (void*)110, p);

    t_dlist* tbh2;
    IS_TRUE(ft_dlist_push_back(&head, tbh2 = ft_create_dlist((void*)10)), i, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, tbh, p);
    EQ(head->next->data, (void*)110, p);
    EQ(head->next->next, tbh2, p);
    EQ(head->next->next->next, NULL, p);
    EQ(head->next->next->data, (void*)10, p);

    MALLOC_LIMIT_SET(0);
    IS_FALSE(ft_dlist_push_front(&head, tbh = ft_create_dlist(NULL)));
    MALLOC_LIMIT_CLEAN();

    free(head);
    free(tbh);
    free(tbh2);
}

static void* clear_check[8];
static int  check_counter;

static void clear_node(void* data)
{
    clear_check[check_counter++] = data;
}

TEST(ft_dlist_clear)
{
    t_dlist* head = NULL;
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");

    ft_list_clear((t_list*)head, &clear_node);
    head = NULL;

    EQ(clear_check[0], (void*)110, p);
    EQ(clear_check[1], (void*)220, p);
    EQ(clear_check[2], (void*)330, p);
    EQ(check_counter, 3);

    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist_i(10)), "malloc error");
    ft_list_clear((t_list*)head, NULL); /* no crash */
}

TEST(ft_dlist_remove_node)
{
    t_dlist* head = NULL;
    t_dlist* n = NULL;
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, n = ft_create_dlist((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_dlist_push_front(&head, ft_create_dlist((void*)110)), "malloc error");
    
    ft_dlist_remove_node(&head, n, NULL);

    EQ(head->data, (void*)110, p);
    EQ(head->prev, NULL, p);
    NE(head->next, NULL, p, ASSERT);
    EQ(head->next->data, (void*)330, p);
    EQ(head->next->prev, head, p);
    EQ(head->next->next, NULL, p);

    ft_dlist_remove_node(&head, head, NULL);
    EQ(head->data, (void*)330, p);
    EQ(head->prev, NULL, p);
    EQ(head->next, NULL, p);

    ft_dlist_remove_node(&head, head, NULL);
    EQ(head, NULL, p);
}

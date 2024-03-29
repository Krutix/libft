#include "ft_list.h"
#define FTST_MALLOC_TEST 1
#include "ftst.h"

#include "stdlib.h"
#include "string.h"

TEST(ft_create_list_i)
{
    char buffer[256];

    t_list* list = ft_create_list_i(sizeof(buffer));

    EQ(MALLOC_SIZE(list), sizeof(t_list) + sizeof(buffer), zu);

    NE(list, NULL, p, ASSERT);

    EQ(list->data, ((void*)list) + sizeof(t_list), p);
    EQ(list->next, NULL, p);

    char test_buffer[sizeof(t_list) + sizeof(buffer)];
    bzero(test_buffer, sizeof(t_list) + sizeof(buffer));

    IS_FALSE(memcmp(((void*)list) + sizeof(t_list), test_buffer, sizeof(buffer)));
    IS_FALSE(memcmp(list->data, test_buffer, sizeof(buffer)));

    free(list);

}

TEST(ft_create_list)
{
    typedef struct {
        char buffer[256];
    } t_test;
    t_list* list = ft_create_list((void*)999);

    EQ(MALLOC_SIZE(list), sizeof(t_list), zu);

    NE(list, NULL, p, ASSERT);

    EQ(list->data, (void*)999, p);
    EQ(list->next, NULL, p);

    free(list);
}

TEST(ft_list_push_front)
{
    t_list* head = NULL;

    IS_TRUE(ft_list_push_front(&head, ft_create_list((void*)220)), i, ASSERT);
    NE(head, NULL, p, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, NULL, p);
    t_list* tbh = head;
    IS_TRUE(ft_list_push_front(&head, ft_create_list((void*)110)), i, ASSERT);
    EQ(head->data, (void*)110, p);
    EQ(head->next, tbh, p);
    EQ(head->next->next, NULL, p);
    EQ(head->next->data, (void*)220, p);

    MALLOC_LIMIT_SET(0);
    IS_FALSE(ft_list_push_front(&head, tbh = ft_create_list(NULL)));
    MALLOC_LIMIT_CLEAN();

    free(head->next);
    free(head);
}

TEST(ft_list_push_back)
{
    t_list* head = NULL;

    IS_TRUE(ft_list_push_back(&head, ft_create_list((void*)220)), i, ASSERT);
    NE(head, NULL, p, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, NULL, p);
    t_list* tbh;
    IS_TRUE(ft_list_push_back(&head, tbh = ft_create_list((void*)110)), i, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, tbh, p);
    EQ(head->next->next, NULL, p);
    EQ(head->next->data, (void*)110, p);

    t_list* tbh2;
    IS_TRUE(ft_list_push_back(&head, tbh2 = ft_create_list((void*)10)), i, ASSERT);
    EQ(head->data, (void*)220, p);
    EQ(head->next, tbh, p);
    EQ(head->next->data, (void*)110, p);
    EQ(head->next->next, tbh2, p);
    EQ(head->next->next->next, NULL, p);
    EQ(head->next->next->data, (void*)10, p);

    MALLOC_LIMIT_SET(0);
    IS_FALSE(ft_list_push_front(&head, tbh = ft_create_list(NULL)));
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

TEST(ft_list_clear)
{
    t_list* head = NULL;
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)330)), "malloc error");
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)220)), "malloc error");
    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list((void*)110)), "malloc error");

    ft_list_clear(head, &clear_node);
    head = NULL;

    EQ(clear_check[0], (void*)110, p);
    EQ(clear_check[1], (void*)220, p);
    EQ(clear_check[2], (void*)330, p);
    EQ(check_counter, 3);

    RUNTIME_ASSERT(ft_list_push_front(&head, ft_create_list_i(10)), "malloc error");
    ft_list_clear(head, NULL); /* no crash */
}

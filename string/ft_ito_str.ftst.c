#include "ft_string.h"
#include <stdint.h>
#include <string.h>

#define FTST_SUB_TEST
#include "ftst.h"

TEST(ft_itoa_base_test)
{
    char *str;
    STR_EQ(str = ft_itoa(0), "0");
    free(str);
    STR_EQ(str = ft_itoa(-1), "-1");
    free(str);
    STR_EQ(str = ft_itoa(1), "1");
    free(str);
    STR_EQ(str = ft_itoa(INT32_MAX), "2147483647");
    free(str);
    STR_EQ(str = ft_itoa(INT32_MIN), "-2147483648");
    free(str);
}

static t_bool  buffer_sanitize(char *buffer)
{
    return (memcmp(buffer, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16) == 0);
}

TEST(ft_utob_base_test)
{
    char buffer[1024];
    char* ptr = &buffer[16];
    bzero(buffer, sizeof(buffer));
    memset(&buffer[16], 's', 100);
    EQ(ft_utob(ptr, 0), 1);
    STR_EQ(ptr, "0");
    IS_TRUE(buffer_sanitize(buffer));
    EQ(ft_utob(ptr, INT32_MAX), 10);
    STR_EQ(ptr, "2147483647");
    IS_TRUE(buffer_sanitize(buffer));
}

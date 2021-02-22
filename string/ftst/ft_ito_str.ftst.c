#include "ft_string.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

    EQ(ft_utob(ptr, UINT64_MAX), 20);
    STR_EQ(ptr, "18446744073709551615");
    IS_TRUE(buffer_sanitize(buffer));
}

TEST(ft_utob_16_base_test)
{
    char* base = "0123456789abcdef";
    char buffer[1024];
    char* ptr = &buffer[16];
    bzero(buffer, sizeof(buffer));
    memset(&buffer[16], 's', 100);
    EQ(ft_utob_16(ptr, 0, base), 1);
    STR_EQ(ptr, "0");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_16(ptr, UINT32_MAX, base), 8);
    STR_EQ(ptr, "ffffffff");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_16(ptr, UINT64_MAX, base), 16);
    STR_EQ(ptr, "ffffffffffffffff");
    IS_TRUE(buffer_sanitize(buffer));
}

TEST(ft_utob_2_base_test)
{
    char buffer[1024];
    char* ptr = &buffer[16];
    bzero(buffer, sizeof(buffer));
    memset(&buffer[16], 's', 100);
    EQ(ft_utob_2(ptr, 0), 1);
    STR_EQ(ptr, "0");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_2(ptr, UINT32_MAX), 32);
    STR_EQ(ptr, "11111111111111111111111111111111");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_2(ptr, UINT64_MAX), 64);
    STR_EQ(ptr, "1111111111111111111111111111111111111111111111111111111111111111");
    IS_TRUE(buffer_sanitize(buffer));
}

TEST(ft_utob_n_base_test)
{
    char* base = "0123456789abcdef";
    char buffer[1024];
    char* ptr = &buffer[16];
    bzero(buffer, sizeof(buffer));
    memset(&buffer[16], 's', 100);

    EQ(ft_utob_n(ptr, UINT32_MAX, base), 8);
    STR_EQ(ptr, "ffffffff");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_n(ptr, UINT64_MAX, base), 16);
    STR_EQ(ptr, "ffffffffffffffff");
    IS_TRUE(buffer_sanitize(buffer));

    base = "0123456789";
    bzero(buffer, sizeof(buffer));
    memset(&buffer[16], 's', 100);
    EQ(ft_utob_n(ptr, 0, base), 1);
    STR_EQ(ptr, "0");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_n(ptr, INT32_MAX, base), 10);
    STR_EQ(ptr, "2147483647");
    IS_TRUE(buffer_sanitize(buffer));

    EQ(ft_utob_n(ptr, UINT64_MAX, base), 20);
    STR_EQ(ptr, "18446744073709551615");
    IS_TRUE(buffer_sanitize(buffer));
}

#include "ft_string.h"

#include "ftst.h"

TEST(ft_atoi_basic_test)
{
	EQ(ft_atoi(""), 0);
	EQ(ft_atoi("+"), 0);
	EQ(ft_atoi("+-11"), 0);
	EQ(ft_atoi("-11"), -11);
	EQ(ft_atoi("+11"), 11);
	EQ(ft_atoi("9223372036854775807"), 9223372036854775807ll, lli);
	EQ(ft_atoi("-9223372036854775808"), -9223372036854775807ll - 1ll, lli);
}

TEST(ft_atoi_base_basic_test)
{
	EQ(ft_atoi_base("", "0123456789"), 0);
	EQ(ft_atoi_base("+", "0123456789"), 0);
	EQ(ft_atoi_base("+-11", "0123456789"), -11);
	EQ(ft_atoi_base("-11", "0123456789"), -11);
	EQ(ft_atoi_base("+11", "0123456789"), 11);
	EQ(ft_atoi_base("9223372036854775807", "0123456789"), 9223372036854775807ll, lli);
	EQ(ft_atoi_base("-9223372036854775808", "0123456789"), -9223372036854775807ll - 1ll, lli);
}

#include "ft_string.h"
#include "stdlib.h"

char	*ft_memjoin(void const *s1, void const *s2,
							size_t len1, size_t len2)
{
	char	*join_str;

	join_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, len1);
	ft_memcpy(join_str + len1, s2, len2);
	join_str[len1 + len2] = '\0';
	return (join_str);
}

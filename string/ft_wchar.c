#include "ft_string.h"
#include "stdio.h"

int	ft_wstrtostr(wchar_t *str, char *buffer)
{
	char *const	buffer_start = buffer;
	int			pr;

	while (*str)
	{
		pr = ft_wchtoch(*str, buffer);
		if (!pr)
			return (-1);
		buffer += pr;
		str++;
	}
	*buffer = '\0';
	return (buffer - buffer_start);
}

int	ft_wstrtostrn(wchar_t *str, char *buffer, size_t n)
{
	char *const	buffer_start = buffer;
	int			pr;

	while (*str && n--)
	{
		pr = ft_wchtoch(*str, buffer);
		if (!pr)
			return (-1);
		buffer += pr;
		str++;
	}
	*buffer = '\0';
	return (buffer - buffer_start);
}

static inline int	ft_chtoch_p2(wchar_t ch, char *buffer)
{
	if (ch <= 0xFFFF)
	{
		buffer[0] = 0xE0 | (ch >> 12);
		buffer[1] = 0x80 | ((ch >> 6) & 0x3F);
		buffer[2] = 0x80 | (ch & 0x3F);
		return (3);
	}
	if (ch <= 0x10FFFF)
	{
		buffer[0] = 0xF0 | (ch >> 18);
		buffer[1] = 0x80 | ((ch >> 12) & 0x3F);
		buffer[2] = 0x80 | ((ch >> 6) & 0x3F);
		buffer[3] = 0x80 | (ch & 0x3F);
		return (4);
	}
	return (0);
}

int	ft_wchtoch(wchar_t ch, char *buffer)
{
	if (ch <= 0)
		return (0);
	if (ch <= 0x7f)
	{
		buffer[0] = ch;
		return (1);
	}
	if (ch <= 0x7ff)
	{
		buffer[0] = 0xC0 | (ch >> 6);
		buffer[1] = 0x80 | (ch & 0x3F);
		return (2);
	}
	return (ft_chtoch_p2(ch, buffer));
}

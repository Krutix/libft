#include "ftst.h"
#include "ft_io.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

TEST(ft_read_next_line)
{
    int fd = open("io/ftst/test-file-1.txt", O_RDONLY);
    char *line;
    EQ(ft_read_next_line(fd, &line)-1, 10);
    STR_EQ(line, "0123456789");
    free(line);
    EQ(ft_read_next_line(fd, &line), 0);
    EQ(line, NULL, p);
}
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror(argv[0]);
        return -1;
    }
    write(fd, "HAHAHA", 6);
    lseek(fd, -2, SEEK_CUR);
    write(fd, "hahaha", 6);
    lseek(fd, 10, SEEK_CUR);
    write(fd, "!!!!!!", 6);
    close(fd);
    return 0;
}


#include <unistd.h> //  read, write, close
#include <fcntl.h>  //  open
#include <stdio.h>

#define PATH "/sys/class/leds/input2::capslock/brightness"

int main()
{
    int output_fd;
    int fd;

    output_fd = open("./output", O_RDONLY);
    if (output_fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    fd = open(PATH, O_WRONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
    }
    if (fd == 1)
    {
        write(fd, "0", 1);
    }
    else
    {
        write(fd, "1", 1);
    }
    close(fd);
    close(output_fd);
    printf("Brightness value written to output file\n");
}
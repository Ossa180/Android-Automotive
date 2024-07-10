#include <unistd.h> //  read, write, close
#include <fcntl.h>  //  open
#include <stdio.h>

#define PATH "/sys/class/leds/input2::capslock/brightness"
#define OUTPUT "./output"

int main()
{
    int fd;
    int output_fd;
    char *buffer[1]; // buffer to store the brightness value

    // Open the file read-only
    fd = open(PATH, O_RDONLY);

    // read the brightness value and store it in buffer
    read(fd, buffer, 1);

    close(fd);

    // Open the file for writing
    output_fd = open(OUTPUT, O_WRONLY);

    // man 2 write , write in the file
    write(output_fd, buffer, 1);
    close(output_fd);
    printf("Brightness value written to output file\n");
}
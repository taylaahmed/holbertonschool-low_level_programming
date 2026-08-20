#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * append_text_to_file - add text to end of file
 * @filename: file to add to
 * @text_content: content to add
 *
 * Return: -1 or 1
 */

void copies_file_content(const char *file_to, const char *file_from);

 int main(int argc, char **argv)
{
    const char *file_to;
    const char *file_from;

    if (argc != 3)
        {
            printf("Error: Can't close fd FD_VALUE\n");
            exit(100);
        }

    file_from = argv[1];
    file_to = argv[2];

    copies_file_content(file_to, file_from);

    return (0);

}

void copies_file_content(const char *file_to, const char *file_from)
{
    int ft;
    int ff;
    char buffer[1024];
    ssize_t byte;

    if (file_from == NULL)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		    exit(98);
        }

    ff = open(file_from, O_RDONLY);
    if (ff == -1)
    {
       dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
       exit(98); 
    }

    ft = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (ft == -1)
	{
		close(ff);
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        exit(99);
	}

    byte = read(ff, buffer, 1024);
	
    while (byte > 0)
    {
        if (write(ft, buffer, byte) == -1)
        {
            close(ff);
            close(ft);
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
        }
        byte = read(ff, buffer, 1024);
    }

    if (byte == -1)
    {
        close(ff);
        close(ft);
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
    }
    
    close(ff);
    close(ft);
}


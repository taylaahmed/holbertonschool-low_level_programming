#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * create_file - create a file in c
 * @filename: file to create
 * @text_content: text to place in file
 *
 * Return: int
 */

int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
    {
        return (-1);
    }

	if (text_content != NULL)
        write(fd, text_content, strlen(text_content));

	close(fd);
	return (1);
}

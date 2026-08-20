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

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND, 0600);
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		close(fd);
		return (-1);
	}

	if (text_content != NULL)
		write(fd, text_content, strlen(text_content));

	close(fd);
	return (1);
}

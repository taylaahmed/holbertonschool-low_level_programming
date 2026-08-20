#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - name of func
 * @filename: is file to read from
 * @letters: number of letters that should be printed
 *
 * Return: value of numbers printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int *size;
	ssize_t byte = 0;
	ssize_t written = 0;

	if (filename == NULL)
		return (0);

	size = malloc(sizeof(char) * letters);
	if (size == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == 0)
	{
		free(size);
		return (0);
	}

	byte = read(fd, size, letters);
	if (byte == -1)
	{
		free(size);
		return (0);
	}

	written = write(STDOUT_FILENO, size, byte);
	if (written != byte || written == -1)
	{
		close(fd);
		free(size);
		return (0);
	}

	close(fd);
	return (byte);
}

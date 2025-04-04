#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <fcntl.h>

/**
 * main - Entry point
 *
 * Description: This function prints a string using puts.
 * Return: Always 0 (Success)
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int w_fd;
	int r_fd;
	char *buffer = malloc(letters * sizeof(char));
	
	if (filename == NULL)
		return (0);
	if (buffer == NULL)
                return (0);
 	fd = open(filename, O_RDONLY);
	r_fd = read(fd, buffer, letters);
	if (r_fd == -1)
		return (0);
	w_fd = write(STDOUT_FILENO, buffer, r_fd);
		if (w_fd == -1)
			return (0);
	if(w_fd != r_fd)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (w_fd);
}

#include <unistd.h>

void buff_checker (char *buffer, int *buff_count, int *total)
{
	if (*buff_count == 1024)/*check the current size of the buffer*/
	{
		write(1, buffer, *buff_count); /*flush the buffer*/
		*total += *buff_count; /*update the total*/
		*buff_count = 0; /*reset the counter to buffer[0]*/
	}
}


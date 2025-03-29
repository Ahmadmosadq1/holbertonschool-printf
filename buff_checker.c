#include <unistd.h>
#include <stdio.h>
void buff_checker(char *buffer, int *buff_count, int *total) 
{
	if (*buff_count > 0) 
	{
		write(1, buffer, *buff_count);
		*total += *buff_count;
		*buff_count = 0;
	}
	
}

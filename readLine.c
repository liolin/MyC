#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readLine();
char* readLine()
{
    size_t blockSize = 8;
    size_t length = 0;
    char *line = malloc(sizeof(char));
    char *buffer = malloc((blockSize) * sizeof(char));
    
    while(1)
    {
	char c = getchar();
	if(c == '\n' || c == EOF)
	    break;
	
	if(length == blockSize)
	{
	    line = realloc(line, (strlen(line) + blockSize + 1) * sizeof(char));
	    line = strncat(line, buffer, blockSize);
	    length = 0;
	}

	buffer[length] = c;
	length++;
    }

    line = strncat(line, buffer, length);
    return line;
}

int main()
{
    char* line = readLine();
    printf("%s\n", line);
    
    return EXIT_SUCCESS;
}

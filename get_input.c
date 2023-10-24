#include "guess.h"

/**
 * get_input - Reads a line from standard input
 * Return: Standard input string
*/
char *get_input(void)
{
	unsigned int buflength = READ_BUFFER, position_size = 0;
	int ch;
	char *line_buffer = malloc(sizeof(char) * buflength);

	if (line_buffer == NULL) /* If malloc fails */
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ch = _getchar();
		if (ch == EOF) /* Handles ctrl + D */
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		if (position_size == 0 && ch == '\n')
		{
			free(line_buffer);
			return (NULL);
		}
		else if (ch == '\n')
		{
			line_buffer[position_size] = '\0';
			return (line_buffer);
		}
		else
			line_buffer[position_size] = ch;
		position_size += 1;
	}
	if (position_size >= buflength)
	{
		buflength += READ_BUFFER;
		line_buffer = _realloc(line_buffer, buflength,
									sizeof(char) * buflength);
		if (line_buffer == NULL)
			exit(EXIT_FAILURE);
	}
}


/**
 * _getchar - Reads a character from stdin
 * Return: The character read (tyypecast as an int)
*/
int _getchar(void)
{
	char ch;

	if (read(0, &ch, 1) == 1)
		return ((int)ch);
	else
		return (EOF);
}

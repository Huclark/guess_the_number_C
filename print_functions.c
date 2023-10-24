#include "guess.h"

/**
 * putchar_ - Prints a character to standard output
 * @c: Character to print
 * Return: Number of bytes successfully written to standard output
*/
int putchar_(char c)
{
	return (write(1, &c, 1));
}


/**
 * puts_ - Prints a string to standard output
 * @str: String to print
*/
void puts_(char *str)
{
	if (str == NULL)
		return;
	while (*str != '\0')
	{
		putchar_(*str);
		str++;
	}
}


/**
 * print_numbers - function prints a decimal (integer) number (base 10)
 * @num_to_print: the num_to_print
 * Return: number of characters printed
 */
int print_numbers(int num_to_print)
{
	int idx, __counter = 0;

	unsigned int absolute, curr_num;

	if (num_to_print < 0)
	{
		absolute = -num_to_print;
		putchar_('-');
		__counter++;
	}
	else
		absolute = num_to_print;
	curr_num = absolute;
	for (idx = 1000000000; idx > 1; idx /= 10)
	{
		if (absolute / idx)
		{
			putchar_('0' + curr_num / idx);
			__counter++;
		}
		curr_num %= idx;
	}
	putchar_('0' + curr_num);
	__counter++;

	return (__counter);
}


#include "guess.h"

/**
 * atoi_ - Converts a string to an integer
 * @string: String to convert to integeger
 * Return: The number converted from the string
 *         0 if no number is found
*/
int atoi_(char *string)
{
	int idx = 0, d = 0, n = 0, length = 0, f = 0, digit = 0;

	while (string[length] != '\0')
		length++;

	while (idx < length && f == 0)
	{
		if (string[idx] == '-')
			++d;

		if (string[idx] >= '0' && string[idx] <= '9')
		{
			digit = string[idx] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (string[idx + 1] < '0' || string[idx + 1] > '9')
				break;
			f = 0;
		}
		idx++;
	}

	if (f == 0)
		return (0);

	return (n);
}


/**
 * is_digit - Checks if a character is a digit
 * @ch: Character to inspect
 * Return: 1 if character is digit
 *         0 if otherwise
*/
int is_digit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}


/**
* stringcompare - Compares two strings
* @string1: A pointer to the 1st string
* @string2: A pointer to the 2nd string
* Return: 0 if string1 = string2
*         positive or negative integer if otherwise
*/

int stringcompare(char *string1, char *string2)
{
	int idx = 0;

	if (string1 == NULL || string2 == NULL)
	{
		if (string1 == NULL && string2 == NULL)
			return (0);
		else
			return (-1);
	}

	while (string1[idx] != '\0' && string2[idx] != '\0')
	{
		if (string1[idx] != string2[idx])
			return (string1[idx] - string2[idx]);

		idx += 1;
	}
	if (string1[idx] != '\0' || string2[idx] != '\0')
		return (string1[idx] - string2[idx]);

	return (0);
}


/**
 * _tolower - Converts uppercase letter to lowercase
 * @c: Character to convert to lowercase
 * Return: Lowercase character
*/
char _tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));

	return (c);
}



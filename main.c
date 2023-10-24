#include "guess.h"

/**
 * main - Runs a game that prompts user to guess a number.
 * Return: Always 0 on success
*/
int main(void)
{
	int status = 1;

	while (status)
	{
		print_prompt();
		guess_loop();
		status = play_again();
	}

	return (0);
}

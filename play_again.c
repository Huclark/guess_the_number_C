#include "guess.h"

/**
 * play_again - Checks if user wants to play again
 * Return: 1 if user wants to play again, 0 if otherwise
*/
int play_again(void)
{
	int i;
	char *user_input;

	puts_("This was fun!\n");
	sleep(1);

	while (1)
	{
		puts_("Do you want to play again? (Yes/No): ");

		user_input = get_input();

		if (user_input == NULL)
			puts_("Invalid input! Please enter \"Yes\" or \"No\".\n");

		for (i = 0 ; user_input[i] ; i++)
			user_input[i] = _tolower(user_input[i]);

		if (stringcompare(user_input, "yes") == 0)
		{
			free(user_input);
			return (1);
		}

		else if (stringcompare(user_input, "no") == 0)
		{
			free(user_input);
			puts_("Thanks for playing :)\n");
			return (0);
		}

		else
		{
			free(user_input);
			puts_("Invalid input! Please enter \"Yes\" or \"No\".\n");
			sleep(1);
		}
	}
}

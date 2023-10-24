#include "guess.h"

/**
 * guess_loop - Handles the guessing loop
*/
void guess_loop(void)
{
	int random_num, max_trials, no_of_tries, counter;
	char *line_buffer;

	srand(time(0)); /* Set the seed for the random number generator */
	random_num = rand() % 100 + 1; /* Randomly generates a number from 1 to 100 */
	max_trials = 5; /* Maximum number of attempts */
	counter = 5; /* Number of attempts left*/

	no_of_tries = 0;
	while (no_of_tries < max_trials)
	{
		counter--;
		puts_("Take a guess: ");

		line_buffer = get_input();

		if (line_buffer == NULL)
		{
			puts_("Invalid input. Please enter a number\n");
			sleep(1);
			attempts_left(counter);
			continue;
		}
		if (check_valid_input(line_buffer, counter, random_num) == 0)
			break;
		no_of_tries++;
	}
	if (no_of_tries == max_trials)
	{
		puts_("Game over! The secret number was 0");
		print_numbers(random_num);
		puts_("\n");
	}
	free(line_buffer);
}


/**
 * valid_input - Checks if user input is a positive integer from
 *               1 to 100
 * @user_input: User input string
 * Return: 0 if user input is valid
 *         1 if user input is a negative integer
 *         2 if user input is not a number
*/
int valid_input(char *user_input)
{
	int i = 1;

	if (user_input[0] == '-')
	{
		while (user_input[i] != '\0')
		{
			if (is_digit(user_input[i]) == 0)
				return (2);
			i++;
		}
		return (1);
	}

	while (*user_input != '\0')
	{
		if (is_digit(*user_input) == 0)
			return (2);
		user_input++;
	}
	return (0);
}


/**
 * attempts_left -  Prints the number of attempts left to standard output
 * @counter: Number of attempts of left
*/
void attempts_left(int counter)
{
	puts_("You have ");
	print_numbers(counter);
	puts_(" attempts left :(\n");
}

/**
 * match_input - Compares user input with random number
 * @counter: Number of attempts left
 * @random_num: Random number to match
 * @line_buffer: Valid input from user
 * Return: 0 if there is a match, 1 if otherwise
*/
int match_input(int counter, int random_num, char *line_buffer)
{
	int user_input = atoi_(line_buffer);

	if (user_input == random_num)
	{
		puts_("Congratulations! You guessed the right number; which is ");
		print_numbers(user_input);
		puts_("!\n");
		return (0);
	}
	else if (user_input < random_num)
	{
		puts_("Try Again! Your guess was too low!\n");
		sleep(1);
		attempts_left(counter);
	}
	else
	{
		puts_("Try Again! Your guess was too high!\n");
		sleep(1);
		attempts_left(counter);
	}

	return (1);
}


/**
 * check_valid_input - Checks for valid input
 * @counter: Number of attempts left
 * @random_num: Random number to match
 * @line_buffer: Valid input from user
 * Return: 0 if there is a match, 1 if otherwise
*/
int check_valid_input(char *line_buffer, int counter, int random_num)
{
	if (valid_input(line_buffer) == 2)
	{
		puts_("Invalid input. Please enter a number\n");
		sleep(1);
		attempts_left(counter);
	}

	else if (valid_input(line_buffer) == 1)
	{
		puts_("Invalid input! Please enter a positive integer from 1 to 100\n");
		sleep(1);
		attempts_left(counter);
	}

	else
	{
		if (match_input(counter, random_num, line_buffer) == 0)
			return (0);
	}

	return (1);
}


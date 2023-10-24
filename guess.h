#ifndef GUESS_H
#define GUESS_H

/* Standard Library Headers */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Custom prototypes for main function */
void print_prompt(void);
void guess_loop(void);
int play_again(void);

/* Custom prototypes for print functions */
void puts_(char *str);
int putchar_(char c);
int print_numbers(int num_to_print);

/* Custom prototypes for memory handling functions */
void *_realloc(void *prev_mem_ptr, unsigned int prev_size,
						unsigned int curr_size);

/* Custom prototypes for string functions */
int atoi_(char *string);
int is_digit(int ch);
int stringcompare(char *string1, char *string2);
char _tolower(char c);

/* Other custom prototypes */
char *get_input(void);
int _getchar(void);
void attempts_left(int counter);
int match_input(int counter, int random_num, char *line_buffer);
int check_valid_input(char *line_buffer, int counter, int random_num);

/* MACROS */
#define READ_BUFFER		1024

#endif

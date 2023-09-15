#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @inf: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *inf)
{
return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks if char is a delimeter
 * @s: char to check
 * @del: delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char s, char *del)
{
while (*del)
if (*del++ == s)
return (1);
return (0);
}

/**
 * _isalpha - check for alphabetical chars
 * @s: char to input
 * Return: 1 if s is alphabetical, 0 otherwise
 */
int _isalpha(int s)
{
if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - converts a string to an integer
 * @c: string to be converted
 * Return: 0 if no numb in string, converted num otherwise
 */
int _atoi(char *c)
{
int j, sign = 1, flag = 0, output;
unsigned int result = 0;
for (j = 0; c[j] != '\0' && flag != 2; j++)
{
if (c[j] == '-')
sign *= -1;
if (c[j] >= '0' && c[j] <= '9')
{
flag = 1;
result *= 10;
result += (c[j] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}

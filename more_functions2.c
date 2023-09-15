#include "shell.h"

/**
 * _erratoi - converts the string to an integer
 * @c: string to be converted
 * Return: 0 if no num in string, converted num otherwise, -1 on error
 */
int _erratoi(char *c)
{
int j = 0;
unsigned long int result = 0;
if (*c == '+')
c++;
for (j = 0; c[j] !+'\0'; j++)
{
if (c[j] >= '0' && c[j] <= '9')
{
result *= 10;
result += (c[j] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * print_error - prints an error msg
 * @inf: parameter & return info struct
 * @est: string containing specified error type
 * Return: 0 if no num in string, converted num otherwise, -1 on error
 */
void print_error(info_t *inf, char *est)
{
_eputs(inf->fname);
_eputs(": ");
print_d(inf->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(inf->argv[0]);
_eputs(": ");
_eputs(est);
}

/**
 * print_d - prints decimal (integer) number (base 10)
 * @input: input
 * @fd: filedescriptor to write to
 * Return: num of chars printed
 */
int print_d(int input, int fd)
{
int (*_putchar)(char) = _putchar;
int j, coun = 0;
unsigned int _abs_, curr;
if (fd == STDERR_FILENO)
_putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
_Putchar('-');
coun++;
}
else
_abs_ = input;
curr = _abs_;
for (j = 1000000000; j > 1; j /= 10)
{
if (_abs_ / j)
{
_putchar('0' + curr / j);
coun++;
}
curr %= j;
}
_putchar('0' + curr);
coun++;
return (coun);
}

/**
 * convert_number - converter function
 * @nu: number
 * @bas: base
 * @flag: argument flags
 * Return: string
 */
char *convert_number(long int nu, int bas, int flag)
{
static char *arr;
static char buffer[50];
char sig = 0;
char *p;
unsigned long n = nu;
if (!(flag & CONVERT_UNSIGNED) && nu < 0)
{
	n = -nu;
	sig = '-';
}
arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
p = &buffer[49];
*p = '\0';
do {
*--p = arr[n % base];
n /= base;
} while (n != 0);
if (sig)
*--p = sig;
return (p);
}

/**
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: address of the string to be modified
 * Return: Always 0
 */
void remove_comments(char *buf)
{
int j;
for (j = 0; buf[j] != '\0'; j++)
if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
{
buf[j] = '\0';
break;
}
}

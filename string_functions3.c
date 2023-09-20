#include "shell.h"

/**
 * _strncpy - copies the string
 * @d: string copy destintion
 * @s: string source
 * @i: number of chars to be copied
 * Return: concatenated string
 */

char *_strncpy(char *d, char *s, int i)
{
int n, m;
char *v = d;
n = 0;
while (s[n] != '\0' && n < i - 1)
{
d[n] = s[n];
n++;
}
if (n < i)
{
m = n;
while (m < i)
{
d[m] = '\0';
m++;
}
}
return (v);
}

/**
 * _strncat - concatenates two string
 * @d: stirng 1
 * @s: string 2
 * @i: amount of bytes to be maximally used
 * Return: concatenated string
 */
char *_strncat(char *d, char *s, int i)
{
int n, m;
char *v = d;
n = 0;
m = 0;
while (d[n] != '\0')
n++;
while (s[m] != '\0' && m < i)
{
d[n] = s[m];
n++;
m++;
}
if (m < i)
d[n] = '\0';
return (v);
}

/**
 * _strchr - locates char in a string
 * @n: string to be parsed
 * @r: char to look for
 * Return: (n) a pointer to the memory area n
 */
char *_strchr(char *n, char r)
{
do {
if (*n == r)
return (n);
} while (*n++ != '\0');
return (NULL);
}


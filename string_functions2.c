#include "shell.h"

/**
 * _strcpy - copies the string
 * @d: destination
 * @s: source
 * Return: pointer to the destination
 */
char *_strcpy(char *d, char *s)
{
int m = 0;
if (d == s || s == 0)
return (d);
while (s[m])
{
d[m] = s[m];
m++;
}
d[m] = 0;
return (d);
}

/**
 * _strdup - duplicates the string
 * @st: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
int len = 0;
char *r;
if (s == NULL)
return (NULL);
while (*s++)
len++;
r = malloc(sizeof(char) * (len + 1));
if (!r)
return (NULL);
for (len++ ; len--;)
r[len] = *--s;
return (r);
}

/**
 * _puts - prints an input string
 * @s: string to be printed
 * Return: Nothing
 */
void _puts(char *s)
{
int m = 0;
if (!s)
return;
while (s[m] != '\0')
{
_putchar(s[m]);
m++;
}
}

/**
 * _putchar - writes char e to stdout
 * @e: char to print
 * Return: 1 if success, -1 if failed, errno 
 */
int _putchar(char e)
{
static int m;
static char buf[WRITE_BUF_SIZE];
if (e == BUF_FLUSH || m >= WRITE_BUF_SIZE)
{
write(1, buf, m);
m = 0;
}
if (e != BUF_FLUSH)
buf[m++] = e;
return (1);
}

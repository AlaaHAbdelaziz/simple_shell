#include "shell.h"

/**
 * strtow - spilits the string into words, Repeated delimiters are ignored
 * @st: input string
 * @de: delimiter string
 * Return: pointer to the array of strings, or NULL if failed
 */

char **strtow(char *st, char *de)
{
int n, o, p, q, nuwords = 0;
char **v;
if (st == NULL || st[0] == 0)
return (NULL);
if (!de)
de = " ";
for (n = 0; st[n] != '\0'; n++)
if (!is_delim(st[n], de) && (is_delim(st[n + 1], de) || !st[n + 1]))
nuwords++;
if (nuwords == 0)
return (NULL);
v = malloc((1 + nuwords) *sizeof(char *));
if (!v)
return (NULL);
for (n = 0, o = 0; o < nuwords; o++)
{
while (is_delim(st[n], de))
n++;
p = 0;
while (!is_delim(st[n + p], de) && st[n + p])
p++;
v[o] = malloc((p + 1) * sizeof(char));
if (!v[o])
{
for (p = 0; p < o; p++)
free(v[p]);
free(v);
return (NULL);
}
for (q = 0; q < p; q++)
v[o][q] = st[n++];
v[o][q] = 0;
}
v[o] = NULL;
return (v);
}

/**
 * strtow2 - splits the string into words
 * @st: input string
 * @de: delimiter
 * Return: pointer to the array of strings, or NULL if failed
 */
char **strtow2(char *st, char de)
{
int n, o, p, q, nuwords = 0;
char **v;
if (st == NULL || st[0] == 0)
return (NULL);
for (n = 0; st[n] != '\0'; n++)
if ((st[n] != de && st[n + 1] == de ||
(st[n] != de && !st[n +1]) || st[n +1] == de))
nuwords++;
if (nuwords == 0)
return (NULL);
v = malloc((1 + nuwords) * sizeof(char *));
if (!v)
return (NULL);
for (n = 0, o = 0; o < nuwords; o++)
{
while (st[n] == de && st[n] != de)
n++;
p = 0;
while (st[n + p] != de && st[n + p] && st[n + p] != de)
p++;
v[o] = malloc((p + 1) * sizeof(char));
if (!v[o])
{
for (p = 0; p < o; p++)
free(v[p]);
free(v);
return (NULL);
}
for (q = 0; q < p; q++)
v[o] [q] = st[n++];
v[o] [q] = 0;
}
v[o] = NULL;
return (v);
}

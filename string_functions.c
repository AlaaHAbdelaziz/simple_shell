#include "shell.h"

/**
 * _strlen - returns length of the string
 * @m: string to be checked
 *
 * Return: length of string
 */
int _strlen(char *m)
{
int s = 0;
if (!m)
return (0);
while (*m++)
s++;
return(s);
}

/**
 * _strcmp - performs lexicographic comparison of two strings
 * @m1: string 1
 * @m2: string 2
 * Return: negative when m1<m2, positive when m1>m2, 0 when m1 == m2
 */
int _strcmp(char *m1, char *m2)
{
while (*m1 && *m2)
{
if (*m1 != *m2)
return (*m1 - *m2);
m1++;
m2++;
}
if (*m1 == *m2)
return (0);
else
return (*m1 < *m2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with hs
 * @hs: string to search
 * @n: substring to find
 * Return: address of next char of hs or NULL
 */
char *starts_with(const char *hs, const char *n)
{
while (*n)
if (*n++ != *hs++)
return (NULL);
return ((char*)hs);
}

/**
 * _strcat - concatenates twos strings
 * @des: destenation buffer
 * @sc: source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *des, char *sc)
{
char *re = des;
while (*des)
des++;
while (*sc)
*des++ = *sc++;
*des = *sc;
return(re);
}

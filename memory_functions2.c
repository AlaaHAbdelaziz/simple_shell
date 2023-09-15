#include "shell.h"

/**
 * bfree - frees a pointer and nulls the address
 * @p: address of the pointer to be free
 * Return: 1 if free, otherwise 0
 */
int bfree(void **p)
{
if (p && *p)
{
free(*p);
*p = NULL;
return (1);
}
return (0);
}

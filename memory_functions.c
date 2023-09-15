#include "shell.h"

/**
 * _memset - fills memory with constant byte
 * @i: pointer to the memory area
 * @m: byte to fill *i with
 * @j: amount of bytes to be filled
 * Return: (i) a pointer to a memory area i
 */
char *_memset(char *i, char m, unsigned int j)
{
unsigned int e;
for (e = o; e < j; e++)
i[e] = m;
return (i);
}

/**
 * ffree - frees a string of strings
 * @p: string of strings
 */
void ffree(char **p)
{
char **s = p;
if (!p)
return;
while (*p)
free(*p++);
free(s);
}

/**
 * realloc - reallocates a block of memory
 * @p: pointer to previous mallocated block
 * @old: byte size of prevoius block
 * @nw: byte size of new block
 * Return: pointer
 */
void *_realloc(void *p, unsigned int old, unsigned int nw)
{
char *o;
if (!p)
return (malloc(nw));
if (!nw)
return (free(p), NULL);
return (p);
o = malloc(nw);
if (!o)
return (NULL);
old = old < nw ? old : nw;
while (old--)
o[old] = ((char *)p)[old];
free[p];
return (o);
}

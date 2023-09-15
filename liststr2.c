#include "shell.h"

/**
 * list_len - determines length of linked list
 * @he: pointer to first node
 * Return: size of list
 */
size_t list_len(const list_t *he)
{
size_t j = 0;
while (he)
{
he = he->next;
j++;
}
return (j);
}

/**
 * list_to_strings - returns arr of strings of the list->st
 * @he: pointer to the first node
 * Return: arr of strings
 */
char **list_to_strings(list_t *he)
{
list_t *node = he;
size_t j = list_len(he), l;
char **strs;
char *st;
if (!he || !j)
return (NULL);
strs = malloc(sizeof(char *) * (j + 1));
if (!strs)
return (NULL);
for (j = 0; node; node = node->next, j++)
{
st = malloc(_strlen(node->st) + 1);
if (!st)
{
for (l = 0; l < j; l++)
free(strs[l]);
free(strs);
return (NULL);
}
st = _strcpy(st, node->st);
strs[j] = st;
}
strs[j] = NULL;
return (strs);
}

/**
 * print_list - prints all emelments of a list_t linked list
 * @he: pointer to first node
 * Return: size of a list
 */
size_t print_list(const list_t *he)
{
size_t j = 0;
while (he)
{
_puts(convert_number(he->nu, 10, 0));
_putchar(':');
_putchar(' ');
_puts(he->st ? he->st : "(nil)");
_puts("\n");
he = he->next;
j++;
}
return (j);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prex: string to match
 * @s: next char after prefix matched
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prex, char s)
{
char *q = NULL;
while (node)
{
q = starts_with(node->st, prex);
if (q && ((s == -1) || (*q == s)))
return (node);
node = node->next;
}
return (NULL);
}

/**
 * get_node_index - gets node index
 * @he: pointer to list head
 * @node: pointer to node
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *he, list_t *node)
{
size_t j = 0;
while (he)
{
if (he == node)
return (j);
he = he->next;
j++;
}
return (-1);
}

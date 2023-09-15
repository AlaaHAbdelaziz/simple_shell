#include "shell.h"

/**
 * add_node - adds a node to th estart of the list
 * @he: address of the pointer to the head node
 * @st: st field of node
 * @nu: node index used by history
 * Return: size of list
 */
list_t *add_node(list_t **he, const char *st, int nu)
{
list_t *new_head;
if (!he)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->nu = nu;
if (st)
{
new_head->st = _strdup(st);
if (!new_head->st)
{
free(new_head);
return (NULL);
}
}
new_head->next = *he;
*he = new_head;
return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @he: address of the pointer to head node
 * @st: st field of node
 * @nu: node index used by history
 * Return: size of list
 */
list_t *add_node_end(list_t **he, const char *st, int nu)
{
list_t *new_node, *node;
if (!he)
return (NULL);
node = *he;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
if (st)
{
new_node->st = _strdup(st);
if (!new_node->st)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*he = new_node;
return (new_node);
}

/**
 * print_list_str - prints st element of a list_t linked list
 * @h1: pointer of the first node
 * Return: size of list
 */
size_t print_list_str(const list_t *h1)
{
size_t j = 0;
while (h1)
{
_puts(h1->st ? h1->st : "(nil)");
_puts("\n");
h1 = h1->next;
j++;
}
return (j);
}

/**
 * delete_node_at_index - deletes node at a given index
 * @he: address of the pointer to the first node
 * @index: index of node to delete
 * Return: 1 on sucess, 0 on failure
 */
int delete_node_at_index(list_t **he, unsigned int index)
{
list_t *node, *prev_node;
unsigned int j = 0;
if (!he || !*he)
return (0);
if (!index)
{
node = *he;
*he = (*he)->next;
free(node->st);
free(node);
return (1);
}
node = *he;
while (node)
{
if (j == index)
{
prev_node->next = node->next;
free(node->st);
free(node);
return (1);
}
j++;
prev_node = node;
node = node->next;
}
return (0);
}

/**
 * free_list - frees all nodes of a list
 * @he_p: address of pointer to head node
 * Return: void
 */
void free_list(list_t **he_p)
{
list_t *node, *next_node, *he;
if (!he_p || !*he_p)
return;
he = *he_p;
node = he;
while (node)
{
next_node = node->next;
free(node->st);
free(node);
node = next_node;
}
*he_p = NULL;
}

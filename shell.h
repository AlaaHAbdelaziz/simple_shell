#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Read and Write Buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Command Channing */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* Convert Numbers */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 If using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @nu: the number field
 * @st: string
 * @next: points to the following node
 */
typedef struct liststr
{
int nu;
char *st;
struct liststr *next;
} list_t;

/**
 * struct passinfo - has pseudo arguments to pass info in function
 * @arg: a string generated from getline()
 * @argv: array of strings from arg
 * @path: the current command path string
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code for exit()
 * @lincount_flag: if on count this line of input
 * @fname: programe filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from ll env
 * @history: history node
 * @alias: alias node
 * @env_changed: if the environ changed
 * @status: return status of the last command
 * @cmd_buf: address of pointer to cmd_buf
 * @cmd_buf_type: cmd_type ||, &&, ;
 * @readfd: the fd from which line input to be read
 * @histcount: line number count in history
 */

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int lincount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf;
int cmd_buf_type;
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - builtin string and related function
 * @type: command flag
 * @func: function
 */

typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;

/* hsh.c */
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);

/* path.c */
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string_functions.c */
int _strlen(char *m);
int _strcmp(char *m1, char *m2);
char *starts_with(const char *hs, const char *n);
char *_strcat(char *des, char *sc);

/* string_functions2.c */
char *_strcpy(char *d, char *s);
char *_strdup(const char *s);
void _puts(char *s);
int _putchar(char e);

/* string_functions3.c */
char *_strncpy(char *d, char *s, int i);
char *_strncat(char *d, char *s, int i);
char *_strchr(char *n, char r);

/* string_functions4.c */
char **strtow(char *st, char *de);
char **strtow2(char *st, char de);

/* memory_functions.c */
char *_memset(char *i, char m, unsigned int j);
void ffree(char **p);
void *_realloc(void *p, unsigned int old, unsigned int nw);

/* memory_functions2.c */
int bfree(void **p);

/* more_functions.c */
int interactive(info_t *inf);
int is_delim(char s, char *del);
int _isalpha(int s);
int _atoi(char *c);

/* more_functions2.c */
int _erratoi(char *c);
void print_error(info_t *inf, char *est);
int print_d(int input, int fd);
char *convert_number(long int nu, int bas, int flag);
void remove_comments(char *buf);

/* builtin_emulators.c */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* builtin_emulators2.c */
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

/* getline.c module */
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused))int sig_num);

/* info.c module */
void clear_info(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int all);

/* env.c module */
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);

/* env2.c module */
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

/* file_io_functions.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int lincount);
int renumber_history(info_t *info);

/* liststr.c module */
list_t *add_node(list_t **he, const char *st, int nu);
list_t *add_node_end(list_t **he, const char *st, int nu);
size_t print_list_str(const list_t *h1);
int delete_node_at_index(list_t **he, unsigned int index);
void free_list(list_t **he_p);

/* liststr2.c module */
size_t list_len(const list_t *he);
char **list_to_strings(list_t *he);
size_t print_list(const list_t *he);
list_t *node_starts_with(list_t *node, char *prex, char s);
ssize_t get_node_index(list_t *he, list_t *node);

/* chain.c */
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);

#endif

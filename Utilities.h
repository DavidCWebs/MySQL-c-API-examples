#ifndef UTILITIES_H
#define UTILITIES_H
#include <mysql.h>
#include <my_global.h>
#include <termios.h>

void show_error(MYSQL *mysql);
ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream);

#endif

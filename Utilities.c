#include "Utilities.h"

void show_error(MYSQL *mysql)
{
	printf("Error(%d) [%s] \"%s\"", mysql_errno(mysql), mysql_sqlstate(mysql), mysql_error(mysql));
	mysql_close(mysql);
	exit(-1);
}

ssize_t my_getpass (char **lineptr, size_t *n, FILE *stream)
{
	struct termios old, new;
	int nread;

	/* Turn echoing off and fail if we can’t. */
	if (tcgetattr(fileno(stream), &old) != 0)
		return -1;
	new = old;
	new.c_lflag &= ~ECHO;
	if (tcsetattr (fileno (stream), TCSAFLUSH, &new) != 0)
		return -1;

	/* Read the passphrase */
	nread = getline (lineptr, n, stream);
	char *end = (*lineptr) + (nread - 1);
	*end = '\0'; // Remove the trailing newline	
	(void) tcsetattr (fileno (stream), TCSAFLUSH, &old);
	return nread;
}



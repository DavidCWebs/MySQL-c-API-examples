#ifndef USERINPUT
#define USERINPUT

#include <stdio.h>
#include <string.h>
#include "Utilities.h"

typedef struct {
	char *host;
	char *userName;
	char *dbName;
	char *password;
} UserData;

void getData(UserData *data);

#endif

#include "UserInput.h"

void getData(UserData *data)
{
	char dbName[32];
	char userName[64];
	size_t passMaxChars = 64;
	char *password = malloc(passMaxChars);


	printf("Enter the name of the Database:\n");
	scanf("%s", dbName);
	getchar();
	printf("Enter the user name for the Database:\n");
	scanf("%s", userName);
	getchar();
	printf("Enter the password:\n");
	my_getpass(&password, &passMaxChars, stdin);

	data->dbName = malloc(strlen(dbName) + 1);
	strcpy(data->dbName, dbName);
	data->userName = malloc(strlen(userName) + 1);
	strcpy(data->userName, userName);
	data->password = malloc(strlen(password) + 1);
	strcpy(data->password, password);
	free(password);
}

#include <stdio.h>
//#include <unistd.h>
#include <mysql.h>
#include <my_global.h>
#include <string.h>
#include "UserInput.h"
#include "Utilities.h"

int main()
{
	char *host = "localhost";
	MYSQL *conn = mysql_init(NULL);

	if(conn == NULL) {
		printf("mysql_init() returns NULL\n");
		return 1;
	}

	if(mysql_real_connect (conn, host, "root", "password123", NULL, 0, NULL, 0) == NULL) {
		printf("Error: cant login\n");
	} else {
		printf("Logged in.\n");
	}

	printf("Server version: %s\n", mysql_get_server_info(conn));
	printf("Client version: %s\n", mysql_get_client_info());
	mysql_close(conn);

	UserData *data = malloc(sizeof(UserData));
	getData(data);

	char query[1024];
	// Create DB string
	// char *create = "CREATE DATABASE";
	// char *createCommand = malloc(strlen(dbName) + 1 + strlen(create));
	// snprintf(createCommand, sizeof(createCommand), "%1$s %2$s");
	// Grant privilege string
	// Flush string
	char *createCommand = "CREATE DATABASE ";
	size_t qLength = strlen(createCommand) + strlen(data->dbName) + 1;
	char *dynamicQuery = malloc(qLength);

	strcpy(dynamicQuery, createCommand);
	strcat(dynamicQuery, data->dbName);
	printf("Dynamic Query: %s\n", dynamicQuery);



	// snprintf(query, sizeof(query), "CREATE DATABASE %1$s;GRANT ALL PRIVILEGES ON %1$s.* TO %2$s@localhost IDENTIFIED BY '%3$s';FLUSH PRIVILEGES;", data->dbName, data->userName, data->password);
	snprintf(query, sizeof(query),
		"CREATE DATABASE %1$s;"
		"GRANT ALL PRIVILEGES ON %1$s.* TO %2$s@localhost "
		"IDENTIFIED BY '%3$s';FLUSH PRIVILEGES;",
		data->dbName,
		data->userName,
		data->password
	);

	printf("The query string for the new database is:\n");
	printf("%s\n", query);
	free(data->dbName);
	free(data->userName);
	free(data->password);
	free(data);

	return 0;
}

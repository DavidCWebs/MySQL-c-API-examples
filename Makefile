SOURCES:= $(wildcard *.c) $(wildcard *.h)
OBJECTS:= $(wildcard *.c)
MYSQL:= $(mysql_config --cflags --libs)
OUT:= bin/main
main: $(SOURCES)
	#cc -W -Wall -o $(OUT) $(OBJECTS) -I/usr/include/mysql -L/usr/lib -lmysqlclient -lpthread -lz -lm -ldl -lssl -lcrypto
	cc -W -Wall -o $(OUT) $(OBJECTS) `mysql_config --cflags --libs`

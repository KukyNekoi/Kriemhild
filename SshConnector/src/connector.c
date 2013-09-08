#include <libssh/libssh.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


#include "connection_functions.c"

int main(int c, char **v)
{
	ssh_session my_ssh_session;
	int verbosity = SSH_LOG_PROTOCOL;
	int port = 22;
	int rc;
	char *password;
	
	my_ssh_session = ssh_new();
	if (my_ssh_session == NULL)
		exit(-1);
	ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, v[1]);
	ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
	ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "root");
	
	
	rc = ssh_connect(my_ssh_session);
	if (rc != SSH_OK)
	{
		fprintf(stderr, "Error connecting to localhost: %s\n",
		ssh_get_error(my_ssh_session));
		exit(-1);
	}
	
	
	// Authenticate ourselves
	password = getpass("Password: ");
	rc = ssh_userauth_password(my_ssh_session, NULL, password);
	if (rc != SSH_AUTH_SUCCESS)
	{
		fprintf(stderr, "Error authenticating with password: %s\n",
		ssh_get_error(my_ssh_session));
		ssh_disconnect(my_ssh_session);
		ssh_free(my_ssh_session);
		exit(-1);
	}

	char buf = 'p', input;
	
	do{
		input = getch();
		if(buf!=input){
			if(input == 'W' || input == 'w' ){
				sendCommand(my_ssh_session, "echo \"F\" > /dev/ttyUSB0");
				printf("echo \"F\" > /dev/ttyUSB0 \n");
			}
			if(input == 'S' || input == 's'){
				sendCommand(my_ssh_session, "echo \"B\" > /dev/ttyUSB0");
				printf("echo \"B\" > /dev/ttyUSB0 \n");
			}
			if(input == 'A' || input == 'a'){
				sendCommand(my_ssh_session, "echo \"L\" > /dev/ttyUSB0");
				printf("echo \"L\" > /dev/ttyUSB0 \n");
			}
			if(input == 'D' || input == 'd'){
				sendCommand(my_ssh_session, "echo \"R\" > /dev/ttyUSB0");
				printf("echo \"R\" > /dev/ttyUSB0 \n");
			}
			if(input == 'X' || input == 'X'){
				sendCommand(my_ssh_session, "echo \"C\" > /dev/ttyUSB0");
				printf("echo \"X\" > /dev/ttyUSB0 \n");
			}
			if(input == 'C' || input == 'c'){
				sendCommand(my_ssh_session, "echo \"N\" > /dev/ttyUSB0");
				printf("echo \"N\" > /dev/ttyUSB0 \n");
			}
		}
		buf = input;
	}while(input != 'z');
	
	
	ssh_disconnect(my_ssh_session);
	ssh_free(my_ssh_session);
}

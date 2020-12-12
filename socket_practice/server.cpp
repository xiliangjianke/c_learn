/*
 * program name:server.cpp, show server of socket communication
 * author:neko date:20201212
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//#include "_public.h"
int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		printf("Using:./server port\nExample:./server 5005\n\n"); return -1;	
	}
	
	// 1.create server socket
	int listenfd;
	if ( (listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		perror("socket"); return -1;	
	}

	// 2.bind port to server socket
	struct sockaddr_in servaddr; // data struct for server address info
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET; // specify protocol

	// servaddr.sin_addr.s_addr = inet_addr("172.17.0.5"); // specify ip
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // any ip address
	servaddr.sin_port = htons(atoi(argv[1])); // specify communication port
	if ( bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 )
	{
		perror("bind"); close(listenfd); return -1;	
	}

	// 3. set socket to listen mode
	if ( listen(listenfd,5) != 0 ) { perror("listen"); close(listenfd); return -1;}

	// 4.accept client connections
	int clientfd; // socket of client
	int socklen = sizeof(struct sockaddr_in); 
	struct sockaddr_in clientaddr; // store address info of client
	clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t*)&socklen);
	printf("client(%s) connected!\n",inet_ntoa(clientaddr.sin_addr));

	// 5.communication with client,reply ok after accept message sent by client
	char buffer[1024];
	while (1)
	{
		int iret;
		memset(buffer, 0, sizeof(buffer));
		if ( (iret=recv(clientfd,buffer,sizeof(buffer),0)) <= 0) // accept message from client
		{
			printf("iret=%d\n",buffer); break;	
		}
		printf("accept: %s\n", buffer);

		strcpy(buffer, "ok");
		if ( (iret=send(clientfd,buffer,strlen(buffer),0)) <= 0) // send message to client
		{
			perror("send"); break;	
		}
		printf("send: %s\n",buffer);
	}

	// 6.close socket,release resource
	close(listenfd); close(clientfd);
}

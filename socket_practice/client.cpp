/*
 * program name:client.cpp, show client of socket communication
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
	if (argc != 3)
	{
		printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); return -1;	
	}
	
	// 1.create client socket
	int sockfd;
	if ( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		perror("socket"); return -1;	
	}

	// 2.rais request to server
	struct hostent* h;
	if ( (h = gethostbyname(argv[1])) == 0) // specify IP of server
	{
		printf("gethostbyname failed.\n"); close(sockfd); return -1;	
	}

	struct sockaddr_in servaddr; // data struct for server address info
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET; // specify protocol

	servaddr.sin_port = htons(atoi(argv[2])); // specify communication port
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);
	if ( connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0) // request to server
	{
		perror("connect"); close(sockfd); return -1;	
	}

	char buffer[1024];

	// 3. communication with server,send a message and wait for reply,then send another
	for (int ii=0;ii<3;ii++)
	{
		int iret;
		memset(buffer, 0, sizeof(buffer));
		sprintf(buffer, "this is %d girl, number:%03d", ii+1,ii+1);

		if ( (iret=send(sockfd,buffer,sizeof(buffer),0)) <= 0) // send message to server
		{
			perror("send"); break;
		}
		printf("send=%s\n",buffer); 
		
		memset(buffer, 0, sizeof(buffer));

		if ( (iret=recv(sockfd,buffer,sizeof(buffer),0)) <= 0) // accept message from client
		{
			printf("iret=%d\n",buffer); break;	
		}
		printf("accept: %s\n", buffer);


	}

	// 6.close socket,release resource
	close(sockfd); 
}

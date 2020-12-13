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


class CTcpClient
{
public:
	int m_sockfd;

	CTcpClient();

	// request to server
	bool connect_to_server(const char *serverip, const int port);
	// send message
	int send(int sockfd, const void *buf, const int buflen, int i);
	//int send(const void *buf, const int buflen);
	// accept message
	//int recv(void *buf, const int buflen);

	int recv(int sockfd, void *buf, const int buflen, int i);

	~CTcpClient();
};
//#include "_public.h"
int main(int argc,char *argv[])
{
	CTcpClient tcp;
	//printf("hello world!\n");

	if ( tcp.connect_to_server("127.0.0.1", 5051) == false)
	{
		printf("tcp.connect_to_server('127.0.0.1', 5051) failed,exit...\n");
		return -1;
	}



	char buffer[1024];

	// 3. communication with server,send a message and wait for reply,then send another
	for (int ii=0;ii<5;ii++)
	{
		int iret;
		memset(buffer, 0, sizeof(buffer));
		sprintf(buffer, "this is %d girl, number:%03d", ii+1,ii+1);

		if ( (tcp.send(tcp.m_sockfd,buffer,strlen(buffer),0)) <= 0) // send message to server
		{
			perror("send"); break;
		}
		printf("send=%s\n",buffer); 
		
		memset(buffer, 0, sizeof(buffer));

		if ( (tcp.recv(tcp.m_sockfd,buffer,sizeof(buffer), 0)) <= 0) // accept message from client
		{
			printf("iret=%d\n",buffer); break;	
		}
		printf("accept: %s\n", buffer);

	}

}

CTcpClient::CTcpClient()
{
	m_sockfd = 0;
}

CTcpClient::~CTcpClient()
{
	if (m_sockfd != 0) close(m_sockfd);	
}

// request to server
bool CTcpClient::connect_to_server(const char *serverip, const int port)
{
	m_sockfd = socket(AF_INET,SOCK_STREAM,0); // create client socket

	struct hostent *h; //struct of ip info
	if ( (h = gethostbyname(serverip)) == 0)
	{
		close(m_sockfd); m_sockfd = 0; return false;	
	}

	// pass ip/port info into struct
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	memcpy(&servaddr.sin_addr,h->h_addr,h->h_length);

	// raise request ro server
	if ( connect(m_sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) != 0 )
	{
		close(m_sockfd); m_sockfd = 0; return false;	
	}

	return true;
}

// send message
int CTcpClient::send(int sockfd, const void *buf, const int buflen, int i)
{
	return send(m_sockfd,buf,buflen,0);	
}

// accept message
int CTcpClient::recv(int sockfd, void *buf, const int buflen, int i)
{
	return recv(m_sockfd,buf,buflen,0);			
}


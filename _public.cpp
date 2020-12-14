/*
 * programname: _public.h, function file of common function declaration
 * author: neko date:20201130
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "_public.h" 

// get smaller integer of two integers
int min(const int ii1,const int ii2)
{
	if (ii1 < ii2) return ii1;

	return ii2;
}

// get bigger integer of two integers
int max(const int ii1,const int ii2)
{
	if (ii1 > ii2) return ii1;

	return ii2;
}

// return int of char
int ctoi(const char chr)
{
	if ((chr >= '0') || (chr <= '9')) return chr-'0';
	return -1;
	/*switch (chr)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}*/
}


// safe strcpy function: copy src to dest
char *STRCPY(char* dest,const size_t dest_size, const char* src)
{
	if (dest == 0) return 0; // if dest if empty string,return 0
	memset(dest,0,sizeof(dest)); // initialize dest

	if (src == 0) return dest; // special case: src is empty string
	
	// if len(src) > dest_size?strncpy:srcpy
	if (strlen(src) > dest_size - 1) { strncpy(dest, src, dest_size - 1); }
	else strcpy(dest, src);

	return dest;
}


// safe strcpy function: copy src to dest
char *STRNCPY(char* dest,const size_t dest_size, const char* src, size_t n)
{
	if (dest == 0) return 0; // if dest if empty string,return 0
	memset(dest,0,sizeof(dest)); // initialize dest

	if (src == 0) return dest; // special case: src is empty string
	
	// if len(src) > dest_size?strncpy:srcpy
	if (n > dest_size - 1) { strncpy(dest, src, dest_size - 1); }
	else strncpy(dest, src, n);

	return dest;
	
}


// safe strcat function
char *STRCAT(char* dest,const size_t dest_size, const char* src)
{
	if (dest == 0) return 0;	
	if (src == 0) return dest;	

	unsigned int free_len = dest_size - strlen(dest) - 1;

	if (free_len > strlen(src)) strcat(dest, src);
	else { strncat(dest, src, free_len); dest[dest_size - 1] = 0; } 

	return dest;
}

// safe strcat function
char *STRNCAT(char* dest,const size_t dest_size, const char* src, const size_t n)
{
	if (dest == 0) return 0;	
	if (src == 0) return dest;	

	unsigned int free_len = dest_size - strlen(dest) - 1;

	if (free_len > n) strncat(dest, src, n);
	else { strncat(dest, src, free_len); dest[dest_size - 1] = 0; } 

	return dest;
}


// delete string to the right of specified char
void DeleteRChar(char *str,const char chr)
{
	if (str == 0) return;	
	if (strlen(str) == 0) return;	

	int str_len = strlen(str);

	while (str_len > 0)
	{
		if (str[str_len - 1] == chr) break;
		str[str_len - 1]=0;
		str_len--;
	}
}

// delete string to the left of specified char
void DeleteLChar(char *str,const char chr)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	char temp_str[strlen(str) + 1];
	memset(temp_str, 0, sizeof(temp_str));
	strcpy(temp_str, str);

	int temp_index = 0;

	while (temp_str[temp_index] != chr) temp_index++;

	memset(str, 0, sizeof(str));
	strcpy(str, temp_str + temp_index);
	
}

// delete string to the left and right of specified char
void DeleteLRChar(char *str,const char chr)
{
	DeleteLChar(str, chr);	
	DeleteRChar(str, chr);	
}

// convert lowercase to uppercase,ignore non alphabetic type
void ToUpper(char *str)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	int len_str = strlen(str);
	int ii = 0;

	for (ii=0;ii<len_str;ii++)
	{
		if ((str[ii] >= 'a') && (str[ii] <= 'z')) str[ii] -= 32;	
	}
}
//void ToUpper(string &str)

// convert uppercase to lowercase,ignore non alphabetic type
void ToLower(char *str)
{
	if (str == 0) return;
	if (strlen(str) == 0) return;

	int len_str = strlen(str);
	int ii = 0;

	for (ii=0;ii<len_str;ii++)
	{
		if ((str[ii] >= 'A') && (str[ii] <= 'Z')) str[ii] += 32;	
	}
}

//void ToLower(string &str)
// parse xml return char string

int get_str_from_XML(const char *xml, const char *filed_name, char *return_value)
{
	char start_label[51];	
	char end_label[51];	
	memset(start_label, 0, sizeof(start_label));
	memset(end_label, 0, sizeof(end_label));

	int len_fn = strlen(filed_name);
	int len_val = 0;

	char *start_index = 0;
	char *end_index = 0;
	//memset(start_index, 0, sizeof(start_index));
	//memset(end_index, 0, sizeof(end_index));

	sprintf(start_label, "<%s>", filed_name);
	sprintf(end_label, "</%s>", filed_name);

	//start_index = (char *)strstr(xml, start_label);
	start_index = (char *)strstr(xml, start_label);

	if (start_index == 0) return -1;
	//else end_index = (char *)strstr(start_index, end_label);
	else end_index = strstr(start_index, end_label);

	if (end_index == 0) return -1;
	else
	{
		len_val = end_index - start_index - len_fn - 2;
		strncpy(return_value, start_index + len_fn + 2, len_val);
	}
	return 0;

}

// pares xml and return int type
int get_int_from_XML(const char *xml, const char *filed_name, int *return_value)
{
	char result[51];
	memset(result, 0, sizeof(result));
	
	//int *return_code = 0;
	
	//return_code = get_str_from_XML(char *xml, char *filed_name, int *return_value);

	if (get_str_from_XML(xml, filed_name, result)!= 0) return -1;
	else (*return_value) = atoi(result);

	return 0;
}

// class of tcp client
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
int CTcpClient::Send(int sockfd, const void *buf, const int buflen, int i)
{
	return send(m_sockfd,buf,buflen,0);	
}

// accept message
int CTcpClient::Recv(int sockfd, void *buf, const int buflen, int i)
{
	return recv(m_sockfd,buf,buflen,0);			
}


// class of tcp server  client

CTcpServer::CTcpServer()
{
	m_listenfd = 0;
	m_clientfd = 0;
}

CTcpServer::~CTcpServer()
{
	if (m_listenfd != 0) close(m_listenfd);	
	if (m_clientfd != 0) close(m_clientfd);	
}


// request to server
bool CTcpServer::init_server(const int port)
{
	m_listenfd = socket(AF_INET,SOCK_STREAM,0); // create client socket


	// pass ip/port info into struct
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	// raise request ro server
	if ( bind(m_listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) != 0 )
	{
		close(m_listenfd); m_listenfd = 0; return false;	
	}

	// set socket to listen mode
	if ( listen(m_listenfd,5) != 0) { close(m_listenfd); m_listenfd=0; return false; }

	return true;
}

// accept client connection
bool CTcpServer::Accept()
{
	if ( (m_clientfd=accept(m_listenfd,0,0)) <= 0 ) return false;
	return true;
}
// send message
int CTcpServer::Send(int sockfd, const void *buf, const int buflen, int i)
{
	return send(m_clientfd,buf,buflen,0);	
}

// accept message
int CTcpServer::Recv(int sockfd, void *buf, const int buflen, int i)
{
	return recv(m_clientfd,buf,buflen,0);			
}




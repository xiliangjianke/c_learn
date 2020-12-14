/*
 * programname: _public.h, header file of common function declaration
 * author: neko date:20201130
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare min function, get smaller integer of two integers
int min(const int ii1,const int ii2);


// declare max function, get bigger integer of two integers
int max(const int ii1,const int ii2);

// declare ctoi function, return int of char 
// return 0 if input is not a integeri
int ctoi(const char chr);

// safe strcpy function: copy src to dest
// dest: target string which will be initialized in
// dest_szie: memory size of dest string
// src: source string
// return value: adress of dest string
char *STRCPY(char* dest,const size_t dest_size, const char* src);

// safe strcpy function: copy src to dest
// dest: target string which will be initialized in
// dest_szie: memory size of dest string
// src: source string
// n: number of bytes for copying 
// return value: adress of dest string
char *STRNCPY(char* dest,const size_t dest_size, const char* src, size_t n);

// safe strcat function
// dest: target string which will be initialized in
// dest_szie: memory size of dest string
// src: source string
// return value: adress of dest string
char *STRCAT(char* dest,const size_t dest_size, const char* src);

// safe strcat function
// dest: target string which will be initialized in
// dest_szie: memory size of dest string
// src: source string
// n: number of bytes for copying 
// return value: adress of dest string
char *STRNCAT(char* dest,const size_t dest_size, const char* src, const size_t n);

// delete specified char at the right of string
// str: target string
// chr: char to be deleted
void DeleteRChar(char *str,const char chr);

// delete specified char at the left of string
// str: target string
// chr: char to be deleted
void DeleteLChar(char *str,const char chr);

// delete specified char on the left and right side of string
// str: target string
// chr: char to be deleted
void DeleteLRChar(char *str,const char chr);

// convert lowercase to uppercase,ignore non alphabetic type
// str: string to be converted,char and string type are suppported
void ToUpper(char *str);
//void ToUpper(string &str);

// convert uppercase to lowercase,ignore non alphabetic type
// str: string to be converted,char and string type are suppported
void ToLower(char *str);
//void ToLower(string &str);

// parse xml and return char string value
// xml: xml string
// filed_name: label which contain value 
// return_value: value between specifid filed_name
// example: xml='<name>neko</name>',get_str_from_XML(xml, 'name', char temp[10]), temp = 'neko'
int get_str_from_XML(const char *xml, const char *filed_name, char *return_value);



// parse xml and return char string value
// xml: xml int
// filed_name: label which contain value 
// return_value: value between specifid filed_name
// example: xml='<age>18<nage>',get_str_from_XML(xml, 'age', char temp[10]), temp = '18'
int get_int_from_XML(const char *xml, const char *filed_name, int *return_value);

// convert integer time to string time
// ltime: time in format integer,such as :time_t tnow;time(&tnow);
// stime: 
//void timetostr(const time_t ltime,char *stime,const char *fmt=0);


class CTcpClient
{
public:
	int m_sockfd;

	CTcpClient();

	// request to server
	bool connect_to_server(const char *serverip, const int port);
	// send message
	int Send(int sockfd, const void *buf, const int buflen, int i);
	//int send(const void *buf, const int buflen);
	// accept message
	//int recv(void *buf, const int buflen);

	int Recv(int sockfd, void *buf, const int buflen, int i);

	~CTcpClient();
};

class CTcpServer
{
public:
	int m_listenfd; // listen socket in server
	int m_clientfd; // client socket which connect to server

	CTcpServer();

	bool init_server(int port); //initialize server

	bool Accept();  // wait for connection

	// send message
	int Send(int sockfd, const void *buf, const int buflen, int i);
	//int send(const void *buf, const int buflen);
	// accept message
	//int recv(void *buf, const int buflen);

	int Recv(int sockfd, void *buf, const int buflen, int i);

	~CTcpServer();
};

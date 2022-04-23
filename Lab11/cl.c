#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include<string.h>
int main()
{
// create socket in client side
int sid = socket(AF_INET, SOCK_STREAM,0);
if(sid <0)
{
perror("Cannot define a TCP socket !!!\n");
exit(1);
}
// define the socket addresses
struct sockaddr_in address;
address.sin_family = AF_INET; //ipv4
address.sin_port = htons(5000);
char server_add[20] = "127.0.0.1";
if(inet_pton(AF_INET, server_add,
&address.sin_addr.s_addr)<0)
{
perror("Cannot convert server address !!!\n");
exit(1);
}
// initiate the connection with server
socklen_t len = sizeof(address);
if( connect(sid,(struct sockaddr*) &address,len) < 0)
{
perror("Cannot establish a TCP connection with server !!!\n");
exit(1);
}
printf("PLz, insert 10 integers :\n");
int up[10];
int i=0;
for(i=0;i<10;i=i+1)
{
scanf("%i",&up[i]);
}
write(sid,up,sizeof(up));
printf("I have send my message to the server ..\n");
}

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<netinet/ip.h>

int main(int argc,char *argv[]){
	int port=atoi(argv[2]);
	struct sockaddr_in seraddr;
	int sd;
	char buffer[20];
	printf("enter the string		: ");
	scanf("%s",&buffer);
	sd=socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(port);
	inet_pton(AF_INET,argv[1],&seraddr.sin_addr);
	connect(sd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	write(sd,buffer,sizeof(buffer));
	read(sd,buffer,sizeof(buffer));
	printf("%s \n",buffer);

}	

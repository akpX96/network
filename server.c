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
int main(int argc,char *argv[] ){

int i=0,j,sd,data;
int port=atoi(argv[1]);
char buffer[30],temp;
struct sockaddr_in serv;
sd=socket(AF_INET,SOCK_STREAM,0);
serv.sin_family=AF_INET;
serv.sin_port=htons(port);
serv.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sd,(struct sockaddr*)&serv,sizeof(serv));
listen(sd,5);
data=accept(sd,(struct sockaddr*)NULL,NULL);
read(data,buffer,sizeof(buffer));
j=strlen(buffer);
while(i<j)
	{
	temp=buffer[j];	
	buffer[j]=buffer[i];
	buffer[i]=temp;
	i++;
	j--;
	}
printf("%s",buffer);
write(data,buffer,sizeof(buffer));
}

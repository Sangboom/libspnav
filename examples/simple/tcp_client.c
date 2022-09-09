#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<inttypes.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define PORTNUM 9000
//client
int main(void)
{
	int sd;
	char buf[256];
	struct sockaddr_in sin;
	
    while(1){
        if((sd=socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            perror("socket");
            exit(1);
        }
        
        memset((char*)&sin, '\0', sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORTNUM);
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        if(connect(sd, (struct sockaddr *)&sin, sizeof(sin)))
        {
            // perror("connect");
            // exit(1);
            sleep(0.1);
        }
        
        if(recv(sd,buf,sizeof(buf),0) == -1)
        {
            // perror("recv");
            // exit(1);
            sleep(0.1);
        }
        printf("From Server : %s\n", buf);
        close(sd);

        sleep(0.5);
        
    }
	

	return 0;
}
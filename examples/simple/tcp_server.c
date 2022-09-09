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

int main(void)
{
	char buf[256];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);
	
    while(1){
        if((sd=socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            perror("socket");
            exit(1);
        }
        int optvalue = 1;	
        setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));
        memset((char *)&sin, '\0', sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORTNUM);
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");

        if(bind(sd, (struct sockaddr *)&sin,sizeof(sin)))
        {
            perror("bind");
            exit(1);
        }

        if(listen(sd,5))
        {
            perror("listen");
            exit(1);
        }

        if((ns=accept(sd,(struct sockaddr *)&cli, &clientlen))==-1)
        {
            perror("accept");
            exit(1);
        }

        sprintf(buf, "sdfsdfsdf %s",inet_ntoa(cli.sin_addr));
        // sprintf(buf, "Your IP address is %s",inet_ntoa(cli.sin_addr));
                
        if(send(ns,buf,strlen(buf) +1, 0) == -1)
        {
            perror("send");
            exit(1);
        }

        close(ns);
        close(sd);
        sleep(0.5);
    }
    
	return 0;
}
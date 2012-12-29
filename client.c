#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
int main(int argc,char **argv)
{
    int sfd,status,red;
    char buf[50],ret;

    struct sockaddr_in servaddr;

    sfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(7004);
    servaddr.sin_addr.s_addr=inet_addr("192.168.1.3");
    connect(sfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    if(i==0)
	   printf("\nConnection Established=%d\n",i);
    else
    {
      	   printf("\nConnection not established=%d\n",i);
      	  exit(0);
    }
for(;;){

        write(1,"\nEnter the Control Command: > ",30);
        red=read(1,buf,sizeof(buf));
        write(sfd,buf,red);
        read(sfd,&c,1);
        sscanf(

       }
 return 0;
}



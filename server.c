/*This is an Introduction on building a server application in GNU/LINUX using C socket API's*/
/*Run this program and issue "netstat -ant | grep 7004" in another terminal, you can see the server listening */

/*accept system call doesnot return till either it encounters an error or gets a connection from a client(such system calls are called as blocking system call */
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> /*for inet_xxxx address format functions*/
int main()
{
    int sd,len,i,red;
    char buf[50];
    char *clientIP;
    clientIP=(char *)malloc(40);

    struct sockaddr_in servaddr,cliaddr;//socket structure
    sd=socket(AF_INET,SOCK_STREAM,0);/*elementary call in any client server application to create an socket*/

    bzero(&servaddr,sizeof(servaddr));//to initialize all elements of the structure to zero
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//To assian a arbitrary IP to the server
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(7004);//port on which the server listens
    bind(sd,(struct sockaddr *)&servaddr,sizeof(servaddr));/*assign the IP and port information to the socket */
    listen(sd,5);/*Listen for incoming coonections */
    len=sizeof(cliaddr);

    i=accept(sd,(struct sockaddr *)&cliaddr,&len);/*accept the incoming connections*/
    clientIP=inet_ntop(cliaddr.sin_addr);
    printf("\n\nConnection succesfully Establised from %s and port number %d\n",clientIP);
    write(1,"\nConnection successfully established \n ",40);
    for(;;){
    red=read(0,buf,sizeof(buf));

    write(i,buf,red);
    }


    //buf[]={0};

    //printf("\nWritten=%d char\n",len);

    return 0;
}


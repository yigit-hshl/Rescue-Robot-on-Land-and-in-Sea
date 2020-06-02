#include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
#include <python2.7/Python.h>
   #include <string>
 #include <iostream>

using namespace std;

void uruchom() {
  Py_Initialize();
   //PyRun_SimpleString("imposrt sys");
   FILE *fd = fopen("s.py", "r");
   PyRun_SimpleFileEx(fd, "s.py", 1);
   Py_Finalize();
   return;
  
}


  int main(void)
  {
    
    struct sockaddr_in sa;
    int res;
    int SocketFD;

    SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (SocketFD == -1) {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    }
  
    memset(&sa, 0, sizeof sa);
  
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1102);
    res = inet_pton(AF_INET, "172.31.12.100", &sa.sin_addr);

    if (connect(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
      perror("connect failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
  
    
     char slowo[100];
     
     while(true) {
     
     read(SocketFD, slowo, 1);
     printf("%c", slowo[0]);
     
     if(slowo[0] == '1') {
       uruchom();
     }
       
     if(slowo[0] == '0'){
       uruchom();       
     }

    }
    shutdown(SocketFD, SHUT_RDWR);
  
    close(SocketFD);
    return EXIT_SUCCESS;
  }
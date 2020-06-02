  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
#include <fstream>
bool uruchomiony = false;

inline bool exists_test (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

  int main(void)
  {
    struct sockaddr_in sa;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (SocketFD == -1) {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    }
  
    memset(&sa, 0, sizeof sa);
  
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1102);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
  
    if (bind(SocketFD,(struct sockaddr *)&sa, sizeof sa) == -1) {
      perror("bind failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
  
    if (listen(SocketFD, 10) == -1) {
      perror("listen failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
  int ConnectFD = accept(SocketFD, NULL, NULL);
    for (;;) {
      
  
      if (0 > ConnectFD) {
        perror("accept failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
      }
  
      /* perform read write operations ... 
      read(ConnectFD, buff, size)
      */
      
      //send(ConnectFD, "1", 1, 0);
      while(true) {
        send(ConnectFD, "5", 1, 0);
        if(exists_test("C:/Users/Startklar/Desktop/rescue_car/src/Rescue Vehicle/CarInterface/start.txt") /*&& uruchomiony == false*/) {
            send(ConnectFD, "1", 1, 0);
            //uruchomiony = true;   
            remove( "C:/Users/Startklar/Desktop/rescue_car/src/Rescue Vehicle/CarInterface/start.txt" );
        }
          
        if(exists_test("C:/Users/Startklar/Desktop/rescue_car/src/Rescue Vehicle/CarInterface/stop.txt") ) {
            send(ConnectFD, "0", 1, 0);
            //uruchomiony = false;
            remove( "C:/Users/Startklar/Desktop/rescue_car/src/Rescue Vehicle/CarInterface/stop.txt" );
        }
      }
      if (shutdown(ConnectFD, SHUT_RDWR) == -1) {
        perror("shutdown failed");
        close(ConnectFD);
        close(SocketFD);
        exit(EXIT_FAILURE);
      }
      
    }
    
    close(ConnectFD);

    close(SocketFD);
    return EXIT_SUCCESS;  
}
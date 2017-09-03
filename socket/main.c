//
//  main.c
//  socket
//
//  Created by DánielBoroznaki on 2016. 02. 17..
//  Copyright © 2016. Dániel Boroznaki. All rights reserved.
//

#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
in_addr_t	 inet_addr(const char *);




int main(int argc, const char * argv[]) {
    int sd = socket(PF_INET, SOCK_STREAM, 0);
    const char ip[12] = "192.168.0.2";
    struct sockaddr_in addr;
    char buf[200];
    long db = 0;
    int i = 0;
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(&ip[0]);
    addr.sin_port = htons(80);
    
    connect(sd, (struct sockaddr*)&addr, sizeof(addr));
    
    send(sd, "GET elso/index.php HTTP/1.0", 27, 0);
    
    db = recv(sd, buf, 200, 0);
    
    if(db > 0){
        for (i = 0; i < 0; i++) {
            printf("%c", buf[i]);
        }
    }
    
    close(sd);
    
    
    return 0;
}

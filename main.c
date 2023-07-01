#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

typedef ssize_t (*send_t)(int sockfd, const void *buf, size_t len, int flags);

ssize_t send(int sockfd, const void *buf, size_t len, int flags)  {
    // size (8B), "GAME"\0, game_data...
    char * game_data = (char*)buf+8+5;

    // manipulate
    if(0 == strncmp(game_data, "HELLO", 5)) {
        strncpy(game_data, "PWNED", 6);
    }

    // send message
    send_t o_send = (send_t)dlsym(RTLD_NEXT, "send");
    return (*o_send)(sockfd, buf, len, flags);
}

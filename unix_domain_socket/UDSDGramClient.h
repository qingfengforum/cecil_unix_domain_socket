/*
 * unix domain socket : SOCK_DGRAM - client
 * 
 * */

#ifndef UDS_DGRAM_SERVER_H_
#define UDS_DGRAM_SERVER_H_

#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>
#include <unistd.h>

class UDSDGramClient {

public:
    bool Init(const char *socket_path);
    void Send(const void *buf, size_t len);


private:
    int sock_fd_;
    struct sockaddr_un sockaddr_;
    size_t sockaddr_size_;
};

#endif
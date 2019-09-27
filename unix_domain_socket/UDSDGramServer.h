/*
 * unix domain socket : SOCK_DGRAM - server
 * 
 * */

#ifndef UDS_DGRAM_SERVER_H_
#define UDS_DGRAM_SERVER_H_

#include <sys/socket.h>
#include <sys/un.h>
#include <stddef.h>
#include <unistd.h>

class UDSDGramServer {

public:
    bool Init(const char *socket_path);
    size_t Receive(void *buf, size_t buf_size);

private:
    int sock_fd_;
};

#endif
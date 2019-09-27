#include <iostream>
#include "UDSDGramServer.h"

using namespace std;

bool UDSDGramServer::Init(const char *socket_path)
{
    int sockfd;
    struct sockaddr_un src_un;

    // create socket
    if ((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
    {
        cerr << "[DGram]create socket failed !" << endl;
        return false;
    }

    // bind
    memset(&src_un, 0, sizeof(src_un));
    src_un.sun_family = AF_UNIX;
    strcpy(src_un.sun_path, socket_path);
    int size = offsetof(struct sockaddr_un, sun_path) + strlen(socket_path);

    unlink(socket_path);  // delete the socket file before bind.
    if (bind(sockfd, (struct sockaddr *)&src_un, size) < 0)
    {
        cerr << "[DGram]socket error" << endl;
        return false;
    }

    // initialize class members
    sock_fd_ = sockfd;

    return true;
}

size_t UDSDGramServer::Receive(void *buf, size_t buf_size)
{
    return recvfrom(sock_fd_, buf, buf_size, 0, NULL, NULL);
}


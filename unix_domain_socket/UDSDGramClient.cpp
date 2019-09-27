#include <iostream>
#include "UDSDGramClient.h"

using namespace std;

bool UDSDGramClient::Init(const char *socket_path)
{
    int sockfd;
    struct sockaddr_un dst_un;

    // create socket
    if ((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
    {
        cerr << "[DGRAM]create socket failed !" << endl;
        return false;
    }

    // 
    memset(&dst_un, 0 , sizeof(dst_un));
    dst_un.sun_family = AF_UNIX;
    strcpy(dst_un.sun_path, socket_path);
    int size = offsetof(struct sockaddr_un, sun_path) + strlen(socket_path);

    // initialize basic info
    sock_fd_ = sockfd;
    memcpy(&sockaddr_, &dst_un, sizeof(dst_un));
    sockaddr_size_ = size;

    #if 0
    time_t t;
    char* str;
    while (1){
        t = time(NULL);
        str = ctime (&t);
        if (str == NULL)
            break;

        //sendto(sockfd, str, strlen(str), 0, (struct sockaddr *)&dst_un, size);
        DGramSend(str, strlen(str));
        sleep(1);
    }
    #endif

    return true;
}

void UDSDGramClient::Send(const void *buf, size_t len)
{
    if (sendto(sock_fd_, buf, len, 0, (struct sockaddr *)&sockaddr_, sockaddr_size_) < 0)
    {
        cerr << "[DGram] send error" << endl;
    }
}
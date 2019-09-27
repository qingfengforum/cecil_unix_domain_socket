#include <iostream>
#include <tools/unix_domain_socket/UDSDGramClient.h>

using namespace std;

int main(int argc, char* argv[])
{
    UDSDGramClient client;
    if (!client.Init("uds_dgram.socket"))
    {
        cerr << " client init error !" << endl;
        return -1;
    }

    time_t t;
    char* str;
    while (1){

        t = time(NULL);
        str = ctime (&t);
        if (str == NULL)
            break;
            
        client.Send(str, strlen(str));
        sleep(1);
    }


    return 0;
}
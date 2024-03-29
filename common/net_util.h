#ifndef __NET_UTIL__HEAD__
#define __NET_UTIL__HEAD__

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#else
#define WIN32_LEAN_AND_MEAN //�ؼ�
#include <WinSock2.h>
#include <ws2tcpip.h>
#include "wepoll.h"
#endif // !_WIN32





#define ERROR_RETURN() \
    printf("file=%s,line=%d,errno=%d,err=%s\n", __FILE__, __LINE__, errno, strerror(errno));\
    return -1;

#define ERROR_RETURN2(x) \
    printf("desc=%s,file=%s,line=%d,errno=%d,err=%s\n", x, __FILE__, __LINE__, errno, strerror(errno));\
    return -1;

#define ERROR_PRINT2(x) \
    printf("desc=%s,file=%s,line=%d,errno=%d,err=%s\n", x, __FILE__, __LINE__, errno, strerror(errno));

extern bool MogoSetNonblocking(int sockfd);
extern int MogoSocket();
extern int MogoBind(int sockfd, const char* pszAddr, unsigned int unPort);
extern int MogoListen(int sockfd, int backlog = 5);
extern int MogoConnect(int fd, const char* pszAddr, unsigned int unPort);
extern void MogoSetBuffSize(int fd, int nRcvBuf, int nSndBuf);
extern void MogoGetBuffSize(int fd);
extern int MogoAsyncRead(int sockfd, void* buf, size_t bufsize, int nTimeout);



#endif		// __NET_UTIL__HEAD__


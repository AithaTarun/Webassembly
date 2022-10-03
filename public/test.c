#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define VNC_BASE 8080
#define DEFAULT_DISPLAY ":10"

int accept_connection (int port)
{
    int bound;
    int sock;
    struct sockaddr_in sin;
    int on = 1;
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons (/*VNC_BASE + port*/8080);

    printf("In\n"); // <-- Getting printed

    bound = socket (AF_INET, SOCK_STREAM, IPPROTO_IP);  // <-- Getting struck

    printf("Out : %d\n", bound);  // <-- Not Getting printed

    if (bound < 0)
    {
        perror ("socket");
        exit (1);
    }

    setsockopt (bound, SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on));

    if (bind (bound, (struct sockaddr *) &sin,
              sizeof (struct sockaddr_in))) {
        perror ("bind");
        exit (1);
    }

    int lStatus = listen (bound, 1);

    printf("Listen status : %d\n", lStatus);

    sock = accept (bound, NULL, 0);

    printf("Accept status : %d\n", sock);

    close (bound);
    return sock;
}

int main()
{
    int clientw = accept_connection (10);
    printf("Client w : %d\n", clientw);
}
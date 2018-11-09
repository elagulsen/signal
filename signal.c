#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int f = open("signal.c", O_WRONLY|O_APPEND);
        write(f,"//Closed due to SIGINT\n",23);
        close(f);
        exit(0);
    }
    if (signo == SIGUSR1) printf("My parent is %d.\n", getppid());
}
int main() {
    
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    
    while(1){
        printf("Hello, my name is %d.\n", getpid());
        sleep(1);
    }
    
}

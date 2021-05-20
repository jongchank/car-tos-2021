#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

struct sigaction act;

void sighandler(int signum, siginfo_t *info, void *ptr)
{
    printf("Received signal %d\n", signum);
    printf("Signal originates from process %lu\n", (unsigned long)info->si_pid);
    sleep(3);
}

int main()
{
    printf("I am %lu\n", (unsigned long)getpid());

    memset(&act, 0, sizeof(act));

    act.sa_sigaction = sighandler;
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &act, NULL);
    
    while (1) {
        sleep(1);
        printf("Main is working\n");
    }

    return 0;
}

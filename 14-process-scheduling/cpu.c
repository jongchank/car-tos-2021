#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int i, rc;
    long sum;
    struct timespec tv;
    time_t sec_old, sec_new;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s number-of-iterations\n", argv[0]);
        return -1;
    }

    rc = clock_gettime(CLOCK_MONOTONIC, &tv);
    if (rc < 0) {
        perror(argv[0]);
        return -1;
    }
    sec_old = tv.tv_sec;    
 
    sum = 0;
    for (i = 0; i < strtol(argv[1], NULL, 10); i++) {
        rc = clock_gettime(CLOCK_MONOTONIC, &tv);
        if (rc < 0) {
            perror(argv[0]);
            return -1;
        }
        sec_new = tv.tv_sec;
        if (sec_new > sec_old + 1) {
            printf("%s: I'm alive. ", argv[0]);
            fflush(stdout);
            sec_old = sec_new;
        }

        sum += i;
    }

    return 0;
}

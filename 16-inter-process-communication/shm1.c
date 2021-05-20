#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATH "/home/jongchank/key"

int main(int argc, char *argv[])
{
    key_t key;
    int shmid, i;
    char *ptr;

    key = ftok(PATH, 'z');
    if (key < 0) {
        perror(argv[0]);
        exit(1);
    }
    shmid = shmget(key, 4096, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror(argv[0]);
        exit(1);
    }

    printf("shmid = %d\n", shmid);

    ptr = shmat(shmid, NULL, 0);
    if (ptr == NULL) {
        perror(argv[0]);
        exit(1);
    }

    for (i = 0; i < 10; i++) {
        ptr[i] = 'A'; 
        printf("Writing A\n");
        sleep(1);
    }
    printf("Press any key\n");
    getchar();
    for (i = 0; i < 10; i++) {
        ptr[i] = 'B'; 
        printf("Writing B\n");
        sleep(1);
    }
    return 0;
}

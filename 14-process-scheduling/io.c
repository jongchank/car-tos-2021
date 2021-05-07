#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN_LINE    100

int main(void)
{
    char command[MAX_LEN_LINE];
    char *s;
    int len;
    
    while (true) {
        printf("MyShell $ ");
        s = fgets(command, MAX_LEN_LINE, stdin);
        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        len = strlen(command);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }
        printf("[%s]\n", command);
      
    }
    return 0;
}

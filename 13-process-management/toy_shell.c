#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_LEN_LINE    100

int main(void)
{
    char command[MAX_LEN_LINE];
    char *args[] = {command, NULL};
    

    int ret, status;
    pid_t pid, cpid;
    
    	
// hostname, cwd, user
    time_t rawtime;
    struct tm *timeinfo; 
    char host_[MAX_LEN_LINE];
    char user_[MAX_LEN_LINE];
    char cwd_[MAX_LEN_LINE];
    char *time_;
    gethostname(host_,MAX_LEN_LINE);
    getcwd(cwd_,MAX_LEN_LINE);
    getlogin_r(user_,MAX_LEN_LINE);    

    while (true) {
        char *s;
        int len;
    	
//time

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	time_ = asctime(timeinfo);

	time_[strlen(time_)-1] = 0;
	printf("\033[1;35m %s ~\033[0m",time_);
//hostname, user print skyblue
	printf("\033[1;36m %s%s ~\033[0m",host_,user_);
//cwd_print purple
	printf("\033[1;35m %s ~\033[0m",cwd_);
	
//command
		
        printf("MyShell $ ");
        s = fgets(command, MAX_LEN_LINE, stdin);
        
	len = strlen(command);

        if (command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }


	//exit 	
	if (strcmp(command,"exit")==0){
		printf("Byebye\n");
		return -1;
	}
	//ls
	
	if(strcmp(command,"ls")==0){
		chdir(s);
		args[0] = "/bin/ls";
	}
	
	//cd
	if(strcmp(command,"cd")==0){
		
	}

	if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
	}
	        
        printf("%d\n", len);

	


        printf("[%s]\n", command);
      
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
            if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
            }
            printf("Child process terminated\n");
            if (WIFEXITED(status)) {
                printf("Exit status is %d\n", WEXITSTATUS(status)); 
            }
        }
        else {  /* child */
            ret = execve(args[0], args, NULL);
            if (ret < 0) {
                fprintf(stderr, "execve failed\n");   
                return 1;
            }
        } 
    }
    return 0;
}
